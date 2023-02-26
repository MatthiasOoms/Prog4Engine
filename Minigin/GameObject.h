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
		Transform GetTransform() const;

		template <typename Comp> Comp* AddComponent();
		template <typename Comp> Comp* GetComponent() const;
		template <typename Comp> void RemoveComponent();

		GameObject() = default;
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
	inline Comp* GameObject::AddComponent()
	{
		m_pComponents.push_back(new Comp{});
		return m_pComponents;
	}

	template<typename Comp>
	inline Comp* GameObject::GetComponent() const
	{
		for (size_t idx{}; idx < m_pComponents.size(); idx++)
		{
			if (dynamic_cast(m_pComponents, Comp))
			{

			}
		}
		return ;
	}

	template<typename Comp>
	inline void GameObject::RemoveComponent()
	{
		m_pComponents.pop_back(new Comp{});
		return m_pComponents;
	}
}
