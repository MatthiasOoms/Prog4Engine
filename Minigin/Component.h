#pragma once
// Why multiple classes in 1 header?
// Only need to include 1 file
// Better overview
#include <memory>

namespace dae
{
	class GameObject;

	class Component
	{
	public:
		Component(GameObject* pOwner);
		virtual ~Component() = default;

		virtual void Update(float elapsedSec, const GameObject* obj) = 0;
		virtual void Render(float elapsedSec, const GameObject* obj) const = 0;

	protected:
		GameObject* m_pOwner;
	};

	class UpdateComponent : public Component
	{
	public:
		UpdateComponent(GameObject* pOwner);
		virtual ~UpdateComponent() = default;

		virtual void Update(float elapsedSec, const GameObject* obj) override = 0;
		virtual void Render(float, const GameObject*) const override {};
	};

	class RenderComponent : public Component
	{
	public:
		RenderComponent(GameObject* pOwner);
		virtual ~RenderComponent() = default;

		virtual void Update(float, const GameObject*) override {};
		virtual void Render(float elapsedSec, const GameObject* obj) const override = 0;
	};
};
