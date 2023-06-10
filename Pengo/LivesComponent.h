#pragma once
#include "CounterComponent.h"

namespace dae
{
	class Subject;
	class Observer;

	class LivesComponent final : public CounterComponent
	{
	public:
		LivesComponent(GameObject* pOwner);

		LivesComponent(const LivesComponent& other) = delete;
		LivesComponent(LivesComponent&& other) = delete;
		LivesComponent& operator=(const LivesComponent& other) = delete;
		LivesComponent& operator=(LivesComponent&& other) = delete;

		virtual void Update(float) override {};
		virtual void Render(float) const override {};

		void Increase() override;
		void Increase(int amount) override;
		void SetValue(int health) override;
	};
}


