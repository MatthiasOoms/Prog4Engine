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

void dae::TransformComponent::SetLocalPosition(const float x, const float y, const float z)
{
	m_LocalPosition.x = x;
	m_LocalPosition.y = y;
	m_LocalPosition.z = z;
}

void dae::TransformComponent::SetWorldPosition(float x, float y, float z)
{
	m_WorldPosition.x = x;
	m_WorldPosition.y = y;
	m_WorldPosition.z = z;
}
