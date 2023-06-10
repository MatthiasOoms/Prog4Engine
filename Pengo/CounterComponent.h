#pragma once
#include "Component.h"

namespace dae
{
	class Subject;
	class Observer;

	class CounterComponent : public Component
	{
	public:
		CounterComponent(GameObject* pOwner);
		virtual ~CounterComponent();

		CounterComponent(const CounterComponent& other) = delete;
		CounterComponent(CounterComponent&& other) = delete;
		CounterComponent& operator=(const CounterComponent& other) = delete;
		CounterComponent& operator=(CounterComponent&& other) = delete;

		virtual void Update(float) override = 0;
		virtual void Render(float) const override = 0;

		virtual void Increase() = 0;
		virtual void Increase(int amount) = 0;
		virtual void SetValue(int value) = 0;
		virtual void AddObserver(Observer* pObserver);
		virtual int GetValue() const;

	protected:
		int m_Value;

		Subject* m_pSubject;
	};
}


