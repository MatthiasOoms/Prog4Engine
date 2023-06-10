#include "LivesComponent.h"
#include "GameObject.h"
#include "Observer.h"
#include "Subject.h"

dae::LivesComponent::LivesComponent(GameObject* pOwner)
	: CounterComponent(pOwner)
{
	SetValue(3);
	m_pSubject = new Subject{};
}

void dae::LivesComponent::Increase()
{
	if (m_Value > 0)
	{
		++m_Value;
		m_pSubject->OnNotify(m_pOwner, Event::PlayerDeath);
	}
}

void dae::LivesComponent::Increase(int amount)
{
	if (m_Value > 0)
	{
		m_Value += amount;
		m_pSubject->OnNotify(m_pOwner, Event::PlayerDeath);
	}
}

void dae::LivesComponent::SetValue(int lives)
{
	if (lives > 0)
	{
		m_Value = lives;
	}
	else
	{
		m_Value = 1;
	}
}
