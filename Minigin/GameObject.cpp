#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "TransformComponent.h"
#include "Component.h"
#include <memory>

dae::GameObject::GameObject()
{
	m_pTransform = std::make_unique<TransformComponent>();
}

dae::GameObject::~GameObject()
{
	for (size_t idx{}; idx < m_pComponents.size(); ++idx)
	{
		delete m_pComponents[idx];
		m_pComponents[idx] = nullptr;
	}

	for (size_t idx{}; idx < m_pChildren.size(); ++idx)
	{
		delete m_pChildren[idx];
		m_pChildren[idx] = nullptr;
	}
}

void dae::GameObject::Update(float deltaTime) 
{
	for (size_t idx{}; idx < m_pComponents.size(); ++idx)
	{
		m_pComponents[idx]->Update(deltaTime);
	}
}

void dae::GameObject::Render(float deltaTime) const
{
	for (size_t idx{}; idx < m_pComponents.size(); ++idx)
	{
		m_pComponents[idx]->Render(deltaTime);
	}
}

dae::TransformComponent& dae::GameObject::GetTransform() const
{
	return *m_pTransform;
}
