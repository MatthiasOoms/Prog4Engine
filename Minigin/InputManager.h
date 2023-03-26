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
	class InputManager final : public Singleton<InputManager>
	{
		using ControllerKey = std::pair<unsigned, Controller::ControllerButton>;
		using ControllerCommandsMap = std::map<ControllerKey, std::unique_ptr<Command>>;
		using KeyboardCommands = std::map<SDL_KeyCode, std::unique_ptr<Command>>;

		ControllerCommandsMap m_ConsoleCommands{};
		KeyboardCommands m_KeyboardCommands{};
		std::vector<std::unique_ptr<Controller>> m_Controllers{};

	public:
		InputManager();
		bool HandleInput(float elapsedSec);

		int AddController();
		void AddCommand(int controllerIdx, Controller::ControllerButton button, std::unique_ptr<Command> pCommand);
		void AddCommand(SDL_KeyCode key, std::unique_ptr<Command> pCommand);
	};
}
