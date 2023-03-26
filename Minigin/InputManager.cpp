#include <windows.h>
#include "InputManager.h"
#include <SDL.h>
#include <Xinput.h>
#include <algorithm> // std::tranform
#include <functional> // std::bit_xor

dae::InputManager::InputManager()
{
	DWORD dwResult;
	for (DWORD i{}; i < XUSER_MAX_COUNT; ++i)
	{
		XINPUT_STATE state;
		ZeroMemory(&state, sizeof(XINPUT_STATE));

		// Simply get the state of the controller from XInput.
		dwResult = XInputGetState(i, &state);

		if (dwResult == ERROR_SUCCESS)
		{
			// Controller is connected
			AddController();
		}
	}

	int size{};
	auto temp = SDL_GetKeyboardState(&size);
	m_pPreviousKeyState = std::vector<Uint8>{ temp, temp + size };

}

bool dae::InputManager::HandleInput(float elapsedSec)
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) 
	{
		if (e.type == SDL_QUIT) 
		{
			return false;
		}
		if (e.type == SDL_KEYDOWN) 
		{
		}
		if (e.type == SDL_MOUSEBUTTONDOWN) 
		{
		}
		// etc...
	}

	int size{};
	auto pCurrentKeyState = SDL_GetKeyboardState(&size);

	// Held this frame
	std::vector<Uint8> myCurrentState{ pCurrentKeyState, pCurrentKeyState + size }; 
	// Held last frame
	std::vector<Uint8> myPreviousState{ m_pPreviousKeyState };

	std::vector<Uint8> myChangedState{}; // For calculations
	std::vector<Uint8> myPressedState{}; // Pressed this frame
	std::vector<Uint8> myReleasedState{}; // Released this frame

	std::transform(myCurrentState.begin(), myCurrentState.end(), myPreviousState.begin(), myChangedState.begin(), std::bit_xor<Uint8>());
	std::transform(myCurrentState.begin(), myCurrentState.end(), myChangedState.begin(), myPressedState.begin(), std::bit_and<Uint8>());
	std::transform(myCurrentState.begin(), myCurrentState.end(), myChangedState.begin(), myReleasedState.begin(), 
		[](Uint8 currentKey, Uint8 changedKey) 
		{
			return static_cast<Uint8>(changedKey & (~currentKey));
		}
	);



	for (auto const& command : m_KeyboardCommands)
	{
		if (myPressedState[command.first.first])
		{
			if (command.first.second == keyState::isDown)
			{
				command.second->Execute(elapsedSec);
			}
		}

		if (pCurrentKeyState[command.first.first])
		{
			if (command.first.second == keyState::isPressed)
			{
				command.second->Execute(elapsedSec);
			}
		}

		if (myReleasedState[command.first.first])
		{
			if (command.first.second == keyState::isUp)
			{
				command.second->Execute(elapsedSec);
			}
		}
	}
	
	for (auto const& controller : m_Controllers)
	{
		controller->Update();
		for (auto const& command : m_ConsoleCommands)
		{
			switch (command.first.second)
			{
				case keyState::isDown:
					{
						if (controller->IsDown(command.first.first.second))
						{
							command.second->Execute(elapsedSec);
						}
					}
				case keyState::isPressed:
					{
						if (controller->IsPressed(command.first.first.second))
						{
							command.second->Execute(elapsedSec);
						}
					}
				case keyState::isUp:
					{
						if (controller->IsUp(command.first.first.second))
						{
							command.second->Execute(elapsedSec);
						}
					}
			}
		}
	}

	m_pPreviousKeyState = std::vector<Uint8>{ pCurrentKeyState, pCurrentKeyState + size };

	return true;
}

int dae::InputManager::AddController()
{
	if (int(m_Controllers.size()) < XUSER_MAX_COUNT)
	{
		m_Controllers.push_back(std::make_unique<Controller>(int(m_Controllers.size())));
	}
	return int(m_Controllers.size());
}

void dae::InputManager::AddCommand(int controllerIdx, Controller::ControllerButton button, keyState state, std::unique_ptr<Command> pCommand)
{
	ControllerKey keyPair{ std::make_pair(controllerIdx, button) };
	ControllerKeyState statePair{ std::make_pair(keyPair, state) };
	m_ConsoleCommands.insert(std::make_pair(statePair, std::move(pCommand)));
}

void dae::InputManager::AddCommand(SDL_KeyCode key, keyState state, std::unique_ptr<Command> pCommand)
{
	KeyboardKey keyPair = std::make_pair(key, state);
	m_KeyboardCommands[keyPair] = std::move(pCommand);
}
