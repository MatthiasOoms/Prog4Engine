#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "Controller.h"
#include <Xinput.h>
#include <iostream>

#pragma comment(lib, "xinput.lib")

namespace dae
{
	class Controller::ControllerImpl
	{
		XINPUT_STATE previousState{};
		XINPUT_STATE currentState{};

		WORD m_ButtonsPressedThisFrame{};
		WORD m_ButtonsReleasedThisFrame{};

		int _controllerIdx;

	public:
		ControllerImpl(int controllerIdx)
			: _controllerIdx{ controllerIdx }
		{
			ZeroMemory(&previousState, sizeof(XINPUT_STATE));
			ZeroMemory(&currentState, sizeof(XINPUT_STATE));
		}

		void Update()
		{
			CopyMemory(&previousState, &currentState, sizeof(XINPUT_STATE));
			ZeroMemory(&currentState, sizeof(XINPUT_STATE));
			XInputGetState(_controllerIdx, &currentState);

			auto buttonChanges = currentState.Gamepad.wButtons ^ previousState.Gamepad.wButtons;
			m_ButtonsPressedThisFrame = buttonChanges & currentState.Gamepad.wButtons;
			m_ButtonsReleasedThisFrame = buttonChanges & (~currentState.Gamepad.wButtons);
		}

		bool IsDownThisFrame(unsigned int button) const { return m_ButtonsPressedThisFrame & button; };
		bool IsUpThisFrame(unsigned int button) const { return m_ButtonsReleasedThisFrame & button; };
		bool IsPressed(unsigned int button) const { return currentState.Gamepad.wButtons & button; };
	};

	Controller::Controller(int controllerIdx)
	{
		pImpl = new ControllerImpl{ controllerIdx };
	}

	Controller::~Controller()
	{
		delete pImpl;
		pImpl = nullptr;
	}

	void Controller::Update()
	{
		pImpl->Update();
	}

	bool Controller::IsDown(ControllerButton button) const
	{
		return pImpl->IsDownThisFrame(static_cast<unsigned int>(button));
	}

	bool Controller::IsUp(ControllerButton button) const
	{
		return pImpl->IsUpThisFrame(static_cast<unsigned int>(button));
	}

	bool Controller::IsPressed(ControllerButton button) const
	{
		return pImpl->IsPressed(static_cast<unsigned int>(button));
	}
}