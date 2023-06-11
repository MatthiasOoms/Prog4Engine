#include "IdleState.h"
#include "MoveState.h"
#include "PlayerComponent.h"
#include <InputManager.h>
#include "GameObject.h"

dae::IdleState::IdleState(PlayerComponent* pPlayer)
    : PlayerState{ pPlayer }
    , m_LastPos{}
{
}

dae::PlayerState* dae::IdleState::HandleInput(float elapsedSec)
{
    // Get GameObject
    auto pOwner = m_pPlayer->GetOwner();

    if (pOwner->GetTransform().GetLocalPosition() != m_LastPos)
    {
        m_LastPos = pOwner->GetTransform().GetLocalPosition();

        return new MoveState{ m_pPlayer };
    }

    return nullptr;
}
