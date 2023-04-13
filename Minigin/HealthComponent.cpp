#include "HealthComponent.h"

dae::HealthComponent::HealthComponent(GameObject* pOwner)
	: UpdateComponent(pOwner)
	, m_MaxHealth{ 10 }
{
	m_CurrentHealth = m_MaxHealth;
}

void dae::HealthComponent::Damage(int amount)
{
	m_CurrentHealth -= amount;
	if (m_CurrentHealth > m_MaxHealth)
	{
		m_CurrentHealth = m_MaxHealth;
	}
	else if (m_CurrentHealth < 0)
	{
		m_CurrentHealth = 0;
	}
}

void dae::HealthComponent::SetMaxHealth(int maxHealth)
{
	if (maxHealth > 0)
	{
		m_MaxHealth = maxHealth;
		if (m_CurrentHealth > m_MaxHealth)
		{
			m_CurrentHealth = m_MaxHealth;
		}
	}
	else
	{
		m_MaxHealth = 1;
		m_CurrentHealth = m_MaxHealth;
	}
}
