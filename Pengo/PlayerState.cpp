#include "PlayerState.h"
#include "PlayerComponent.h"

dae::PlayerState::PlayerState(PlayerComponent* pPlayer)
	: m_pPlayer{ pPlayer }
{
}

dae::PlayerState::~PlayerState()
{
	delete m_pPlayer;
	m_pPlayer = nullptr;
}
