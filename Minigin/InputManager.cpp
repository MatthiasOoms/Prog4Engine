#include <windows.h>
#include "InputManager.h"
#include <SDL.h>
#include <Xinput.h>

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
			for (auto const& command : m_KeyboardCommands)
			{
				if (e.key.keysym.sym == command.first)
				{
					command.second->Execute(elapsedSec);
				}
			}
		}
		if (e.type == SDL_MOUSEBUTTONDOWN) 
		{
			
		}
		// etc...
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

void dae::InputManager::AddCommand(SDL_KeyCode key, std::unique_ptr<Command> pCommand)
{
	m_KeyboardCommands[key] = std::move(pCommand);
}
