#include <SDL.h>
#include "InputManager.h"
#include <Xinput.h>
#include <Windows.h>

void dae::InputManager::HandleInput()
{
}

bool dae::InputManager::IsPressed(int button)
{
	button;

	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return false;
		}
		if (e.type == SDL_KEYDOWN) {
			
		}
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			
		}
		// etc...
	}

	return true;
}
