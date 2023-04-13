#include "HealthComponent.h"
#include "Subject.h"
#include "Observer.h"

dae::HealthComponent::HealthComponent(GameObject* pOwner)
	: UpdateComponent(pOwner)
	, m_CurrentHealth{ 10 }
{
	m_pSubject = new Subject{};
}

void dae::HealthComponent::AddObserver(Observer* pObserver)
{
	m_pSubject->addObserver(pObserver);
}

void dae::HealthComponent::Damage(int amount)
{
	m_CurrentHealth -= amount;
	if (m_CurrentHealth <= 0)
	{
		m_pSubject->Notify(Event::PlayerDeath);
	}
}

void dae::HealthComponent::SetHealth(int health)
{
	if (health > 0)
	{
		m_CurrentHealth = health;
	}
	else
	{
		m_CurrentHealth = 1;
	}
}
