#pragma once
#include <memory>
#include "Transform.h"
#include <vector>

namespace dae
{
	class Component;
	class Transform;

	// todo: this should become final.
	class GameObject final
	{
	public:
		void Update(float deltaTime);
		void Render(float deltaTime) const;
		Transform& GetTransform() const;

		template <typename Comp> Comp* AddComponent(GameObject* pOwner);
		template <typename Comp> Comp* GetComponent() const;
		template <typename Comp> bool HasComponent() const;
		template <typename Comp> void RemoveComponent();

		GameObject();
		~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

	private:
		std::unique_ptr<Transform> m_pTransform;
		std::vector<Component*> m_pComponents;
	};

	template<typename Comp>
	inline Comp* GameObject::AddComponent(GameObject* pOwner)
	{
		// TODO: Implement check to see if Inherits from base class Component
		// Use a static_assert for it
		Comp* temp{ new Comp{ pOwner } };
		m_pComponents.push_back(temp);
		return temp;
	}

	template<typename Comp>
	inline Comp* GameObject::GetComponent() const
	{
		Comp* temp;
		for (size_t idx{}; idx < m_pComponents.size(); idx++)
		{
			temp = dynamic_cast<Comp*>(m_pComponents[idx]);
			if (temp != nullptr)
			{
				return temp;
			}
		}
		return nullptr;
	}

	template<typename Comp>
	inline void GameObject::RemoveComponent()
	{
		Comp* temp;
		for (size_t idx{}; idx < m_pComponents.size(); idx++)
		{
			temp = dynamic_cast<Comp*>(m_pComponents[idx]);
			if (temp != nullptr)
			{
				delete m_pComponents[idx];
				m_pComponents[idx] = nullptr;

				auto nth = m_pComponents.begin() + idx;
				m_pComponents.erase(nth);
			}
		}
	}

	template<typename Comp>
	inline bool GameObject::HasComponent() const
	{
		Comp* temp;
		for (size_t idx{}; idx < m_pComponents.size(); idx++)
		{
			temp = dynamic_cast<Comp*>(m_pComponents[idx]);
			if (temp != nullptr)
			{
				return true;
			}
		}
		return false;
	}
}
