#include "PlayerComponent.h"
#include "PlayerState.h"
#include "IdleState.h"

dae::GameObject* dae::PlayerComponent::GetOwner() const
{
	return m_pOwner;
}

dae::PlayerComponent::PlayerComponent(GameObject* pOwner)
	: Component(pOwner)
	, m_pState{ new IdleState{ this } }
{
}

dae::PlayerComponent::~PlayerComponent()
{
	delete m_pState;
	m_pState = nullptr;
}

void dae::PlayerComponent::HandleInput(float elapsedSeconds)
{
	PlayerState* newState = m_pState->HandleInput(elapsedSeconds);
	if (newState != nullptr)
	{
		// Exit
		m_pState->OnExit();

		// Change
		m_pState = newState;

		// Enter
		m_pState->OnEnter();
	}
}

void dae::PlayerComponent::Update(float elapsedSeconds)
{
	m_pState->Update(elapsedSeconds);

	HandleInput(elapsedSeconds);
}
