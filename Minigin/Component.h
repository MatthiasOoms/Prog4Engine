#pragma once
// Why multiple classes in 1 header?
// Only need to include 1 file
// Better overview

namespace dae
{
	class GameObject;

	class Component
	{
	public:
		Component() = default;
		virtual ~Component() = default;

		virtual void Update(float elapsedSec, const GameObject* obj) = 0;
		virtual void Render(float elapsedSec, const GameObject* obj) const = 0;
	};

	class UpdateComponent : public Component
	{
	public:
		UpdateComponent() = default;
		virtual ~UpdateComponent() = default;

		virtual void Update(float elapsedSec, const GameObject* obj) override = 0;
		virtual void Render(float, const GameObject*) const override {};
	};

	class RenderComponent : public Component
	{
	public:
		RenderComponent() = default;
		virtual ~RenderComponent() = default;

		virtual void Update(float, const GameObject*) override {};
		virtual void Render(float elapsedSec, const GameObject* obj) const override = 0;
	};
};
