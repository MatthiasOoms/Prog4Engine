#pragma once
// Why multiple classes in 1 header?
// Only need to include 1 file
// Better overview

class GameObject;

namespace dae
{
	class Component
	{
	public:
		Component() = default;
		virtual ~Component() = 0;

		virtual void Update(float elapsedSec, const GameObject* obj) = 0;
		virtual void Render(float elapsedSec, const GameObject* obj) const = 0;
	};

	class UpdateComponent : public Component
	{
	public:
		UpdateComponent() = default;
		virtual ~UpdateComponent() = 0;

		virtual void Update(float elapsedSec, const GameObject* obj) override = 0;
	};

	class RenderComponent : public Component
	{
	public:
		RenderComponent() = default;
		virtual ~RenderComponent() = 0;

		virtual void Render(float elapsedSec, const GameObject* obj) const override = 0;
	};
};