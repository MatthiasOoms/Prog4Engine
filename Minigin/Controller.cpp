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
		XINPUT_STATE m_PreviousState{};
		XINPUT_STATE m_CurrentState{};

		WORD m_ButtonsPressedThisFrame{};
		WORD m_ButtonsReleasedThisFrame{};

		int m_ControllerIdx;

	public:
		ControllerImpl(int controllerIdx)
			: m_ControllerIdx{ controllerIdx }
		{
			ZeroMemory(&m_PreviousState, sizeof(XINPUT_STATE));
			ZeroMemory(&m_CurrentState, sizeof(XINPUT_STATE));
		}

		void Update()
		{
			CopyMemory(&m_PreviousState, &m_CurrentState, sizeof(XINPUT_STATE));
			ZeroMemory(&m_CurrentState, sizeof(XINPUT_STATE));
			XInputGetState(m_ControllerIdx, &m_CurrentState);

			auto buttonChanges = m_CurrentState.Gamepad.wButtons ^ m_PreviousState.Gamepad.wButtons;
			m_ButtonsPressedThisFrame = buttonChanges & m_CurrentState.Gamepad.wButtons;
			m_ButtonsReleasedThisFrame = buttonChanges & (~m_CurrentState.Gamepad.wButtons);
		}

		bool IsDownThisFrame(unsigned int button) const { return m_ButtonsPressedThisFrame & button; };
		bool IsUpThisFrame(unsigned int button) const { return m_ButtonsReleasedThisFrame & button; };
		bool IsPressed(unsigned int button) const { return m_CurrentState.Gamepad.wButtons & button; };
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