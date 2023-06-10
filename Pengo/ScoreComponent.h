#pragma once
#include "CounterComponent.h"
namespace dae
{
	class Subject;
	class Observer;

	class ScoreComponent final : public CounterComponent
	{
	public:
		ScoreComponent(GameObject* pOwner);

		ScoreComponent(const ScoreComponent& other) = delete;
		ScoreComponent(ScoreComponent&& other) = delete;
		ScoreComponent& operator=(const ScoreComponent& other) = delete;
		ScoreComponent& operator=(ScoreComponent&& other) = delete;

		virtual void Update(float) override {};
		virtual void Render(float) const override {};

		void Increase() override;
		void Increase(int amount) override;
		void SetValue(int value) override;
	};
}

