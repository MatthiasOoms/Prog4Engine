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

		virtual void Update(float elapsedSec) = 0;
		virtual void Render(float elapsedSec) const = 0;

	protected:
		GameObject* m_pOwner;
	};

	class UpdateComponent : public Component
	{
	public:
		UpdateComponent(GameObject* pOwner);
		virtual ~UpdateComponent() = default;

		virtual void Update(float elapsedSec) override = 0;
		virtual void Render(float) const override {};
	};

	class RenderComponent : public Component
	{
	public:
		RenderComponent(GameObject* pOwner);
		virtual ~RenderComponent() = default;

		virtual void Update(float) override {};
		virtual void Render(float elapsedSec) const override = 0;
	};
};
