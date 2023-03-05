#include "TransformComponent.h"
#include "GameObject.h"

dae::TransformComponent::TransformComponent(GameObject* pOwner)
	: Component(pOwner)
	, m_LocalPosition{}
	, m_WorldPosition{}
{
	m_WorldPosition = m_pOwner->GetTransform().GetWorldPosition();
}

dae::TransformComponent::~TransformComponent()
{
}

void dae::TransformComponent::UpdateWorldPosition()
{
	m_WorldPosition = m_pOwner->GetTransform().GetWorldPosition() + m_LocalPosition;
}

void dae::TransformComponent::SetLocalPosition(const float x, const float y, const float z)
{
	m_LocalPosition.x = x;
	m_LocalPosition.y = y;
	m_LocalPosition.z = z;
}