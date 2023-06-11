#include "MoveState.h"
#include "IdleState.h"
#include "PlayerComponent.h"
#include <InputManager.h>
#include "GameObject.h"

dae::MoveState::MoveState(PlayerComponent* pPlayer)
    : PlayerState{ pPlayer }
    , m_LastPos{}
    , m_MoveDir{}
{
}

dae::PlayerState* dae::MoveState::HandleInput(float elapsedSec)
{
    // Get GameObject
    auto pOwner = m_pPlayer->GetOwner();

    // If not moving
    if (pOwner->GetTransform().GetLocalPosition() == m_LastPos)
    {
        // Go Idle
        return new IdleState{ m_pPlayer };
    }

    return nullptr;
}

void dae::MoveState::Update(float elapsedSec)
{
    // Get position, add movement
    auto movement = m_pPlayer->GetOwner()->GetTransform().GetLocalPosition() + m_MoveDir * elapsedSec;

    // Apply movement
    m_pPlayer->GetOwner()->GetTransform().SetLocalPosition(movement.x, movement.y, movement.z);
}

void dae::MoveState::OnEnter()
{
    // Get owner
    auto pOwner = m_pPlayer->GetOwner();

    // Calculate Movement Direction
    m_MoveDir = pOwner->GetTransform().GetLocalPosition() - m_LastPos;
}
