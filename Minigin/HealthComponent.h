#pragma once
#include "Component.h"

namespace dae
{
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

		void Damage(int amount);
		void SetMaxHealth(int health);

	private:
		int m_MaxHealth;
		int m_CurrentHealth;
	};
}


