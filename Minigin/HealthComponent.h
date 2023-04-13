#pragma once
#include "Component.h"

namespace dae
{
	class Subject;
	class Observer;

	class HealthComponent final : public UpdateComponent
	{
	public:
		HealthComponent(GameObject* pOwner);
		~HealthComponent() = default;

		HealthComponent(const HealthComponent& other) = delete;
		HealthComponent(HealthComponent&& other) = delete;
		HealthComponent& operator=(const HealthComponent& other) = delete;
		HealthComponent& operator=(HealthComponent&& other) = delete;

		virtual void Update(float) override {};
		virtual void Render(float) const override {};

		void AddObserver(Observer* pObserver);
		void Damage(int amount);
		void SetHealth(int health);

	private:
		int m_CurrentHealth;

		Subject* m_pSubject;
	};
}


