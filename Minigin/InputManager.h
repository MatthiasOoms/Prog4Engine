#pragma once
#include "Singleton.h"

namespace dae
{
	class InputManager final : public Singleton<InputManager>
	{
		using ControllerKey = std::pair<unsigned, 

	public:
		bool ProcessInput();
	};

}
