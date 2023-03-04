#include "TransformComponent.h"

dae::TransformComponent::TransformComponent(GameObject* pOwner)
	: Component(pOwner)
	, m_position{}
{
}

dae::TransformComponent::~TransformComponent()
{
}

void dae::TransformComponent::SetPosition(const float x, const float y, const float z)
{
	m_position.x = x;
	m_position.y = y;
	m_position.z = z;
}