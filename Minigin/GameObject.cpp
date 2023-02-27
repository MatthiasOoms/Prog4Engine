#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Transform.h"
#include "Component.h"
#include <memory>

dae::GameObject::GameObject()
{
	m_pTransform = std::make_unique<Transform>();
}

dae::GameObject::~GameObject()
{
	for (size_t idx{}; idx < m_pComponents.size(); ++idx)
	{
		delete m_pComponents[idx];
		m_pComponents[idx] = nullptr;
	}
}

void dae::GameObject::Update(float deltaTime) 
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

dae::Transform& dae::GameObject::GetTransform() const
{
	return *m_pTransform;
}
