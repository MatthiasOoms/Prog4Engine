#include <windows.h>
#include "InputManager.h"
#include <SDL.h>
#include <Xinput.h>

bool dae::InputManager::HandleInput()
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

	return true;
}

int dae::InputManager::AddController()
{
	m_Controllers.push_back(std::make_unique<Controller>(int(m_Controllers.size()) + 1));
	return int(m_Controllers.size());
}

void dae::InputManager::AddCommand(Controller::ControllerButton button, std::unique_ptr<Command> pCommand, int controllerIdx)
{
	ControllerKey keyPair{ std::make_pair(controllerIdx, button) };
	m_ConsoleCommands.insert(std::make_pair(keyPair, std::move(pCommand)));
}
