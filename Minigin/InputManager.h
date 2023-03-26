#pragma once
#include "Singleton.h"
#include "Controller.h"
#include "Command.h"
#include <vector>
#include <memory>
#include <SDL.h>
#include <map>

namespace dae
{
	enum class keyState
	{
		isDown,		// Down this frame
		isPressed,	// Held this frame
		isUp		// Released this frame
	};

	class InputManager final : public Singleton<InputManager>
	{
		using ControllerKey = std::pair<unsigned, Controller::ControllerButton>;
		using ControllerKeyState = std::pair<ControllerKey, keyState>;
		using ControllerCommandsMap = std::map<ControllerKeyState, std::unique_ptr<Command>>;

		using KeyboardKey = std::pair<SDL_KeyCode, keyState>;
		using KeyboardCommands = std::map<KeyboardKey, std::unique_ptr<Command>>;

		ControllerCommandsMap m_ConsoleCommands{};
		KeyboardCommands m_KeyboardCommands{};
		std::vector<std::unique_ptr<Controller>> m_Controllers{};

		const Uint8* m_pCurrentKeyState{};
		const Uint8* m_pPreviousKeyState{};

	public:
		InputManager();
		bool HandleInput(float elapsedSec);

		int AddController();
		void AddCommand(int controllerIdx, Controller::ControllerButton button, keyState state, std::unique_ptr<Command> pCommand);
		void AddCommand(SDL_KeyCode key, keyState state, std::unique_ptr<Command> pCommand);
	};
}
