#pragma once
#include "Singleton.h"
#include "Controller.h"
#include "Command.h"
#include <vector>
#include <memory>
#include <map>

namespace dae
{
	class InputManager final : public Singleton<InputManager>
	{
		using ControllerKey = std::pair<unsigned, Controller::ControllerButton>;
		using ControllerCommandsMap = std::map<ControllerKey, std::unique_ptr<Command>>;
		ControllerCommandsMap m_ConsoleCommands{};
		std::vector<std::unique_ptr<Controller>> m_Controllers{};

	public:
		bool HandleInput();

		int AddController();
		void AddCommand(Controller::ControllerButton button, std::unique_ptr<Command> pCommand, int controllerIdx);
	};
}
