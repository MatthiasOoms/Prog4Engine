#include "LivesComponent.h"
#include "Observer.h"
#include "Subject.h"

dae::LivesComponent::LivesComponent(GameObject* pOwner)
	: UpdateComponent(pOwner)
	, m_CurrentLives{ 3 }
{
	m_pSubject = new Subject{};
}

void dae::LivesComponent::AddObserver(Observer* pObserver)
{
	m_pSubject->addObserver(pObserver);
}

int dae::LivesComponent::GetLives() const
{
	return m_CurrentLives;
}

void dae::LivesComponent::Damage()
{
	if (m_CurrentLives > 0)
	{
		--m_CurrentLives;
		m_pSubject->Notify(*m_pOwner, Event::PlayerDeath);
	}
}

void dae::LivesComponent::Damage(int amount)
{
	if (m_CurrentLives > 0)
	{
		m_CurrentLives -= amount;
		m_pSubject->Notify(*m_pOwner, Event::PlayerDeath);
	}
}

void dae::LivesComponent::SetLives(int lives)
{
	if (lives > 0)
	{
		m_CurrentLives = lives;
	}
	else
	{
		m_CurrentLives = 1;
	}
}
