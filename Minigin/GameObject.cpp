#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "TransformComponent.h"
#include "Component.h"
#include <memory>

dae::GameObject::GameObject()
{
	m_pTransform = std::make_unique<TransformComponent>(this);
}

dae::GameObject::GameObject(GameObject* pParent)
	: m_pParent{ pParent }
	, m_IsPositionDirty { true }
	, m_pTransform { std::make_unique<TransformComponent>(this) }
{
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

dae::GameObject* dae::GameObject::GetParent() const
{
	return m_pParent.get();
}

void dae::GameObject::SetParent(GameObject* pParent, bool keepWorldPosition)
{
	if (m_pParent == nullptr)
	{
		SetLocalPosition(GetWorldPosition());
	}
	else if (keepWorldPosition)
	{
		// Maths might be off
		SetLocalPosition(GetLocalPosition() + m_pParent->GetWorldPosition());
		SetPositionDirty();
	}
	if (m_pParent)
	{
		m_pParent->RemoveChild(this);
	}

	m_pParent = std::make_unique<GameObject>(pParent);

	if (m_pParent)
	{
		m_pParent->AddChild(this);
	}
}

int dae::GameObject::GetChildCount() const
{
	return int(m_pChildren.size());
}

dae::GameObject* dae::GameObject::GetChildAt(int idx) const
{
	if (idx < GetChildCount())
	{
		return m_pChildren[idx];
	}
	return nullptr;
}

void dae::GameObject::AddChild(GameObject* pChild)
{
	m_pChildren.push_back(pChild);
}

void dae::GameObject::RemoveChild(GameObject* pChild)
{
	std::erase(m_pChildren, pChild);
}

const glm::vec3& dae::GameObject::GetLocalPosition() const
{
	return m_pTransform->GetLocalPosition();
}

const glm::vec3& dae::GameObject::GetWorldPosition() const
{
	if (m_IsPositionDirty)
	{
		m_pTransform->UpdateWorldPosition();
	}
	return m_pTransform->GetWorldPosition();
}

void dae::GameObject::SetLocalPosition(const glm::vec3& pos)
{
	m_pTransform->SetLocalPosition(pos.x, pos.y, pos.z);
	SetPositionDirty();
}

void dae::GameObject::SetPositionDirty()
{
	m_IsPositionDirty = true;
}
