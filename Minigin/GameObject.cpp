#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Transform.h"
#include "Component.h"

dae::GameObject::~GameObject() = default;

void dae::GameObject::Update([[maybe_unused]] float deltaTime) 
{
	for (size_t idx{}; idx < m_pComponents.size(); ++idx)
	{
		m_pComponents[idx]->Update(deltaTime, this);
	}
}

void dae::GameObject::Render(float deltaTime) const
{
	for (size_t idx{}; idx < m_pComponents.size(); ++idx)
	{
		m_pComponents[idx]->Render(deltaTime, this);
	}
}

dae::Transform dae::GameObject::GetTransform() const
{
	return Transform();
}
