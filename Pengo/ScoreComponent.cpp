#include "ScoreComponent.h"
#include "GameObject.h"
#include "Observer.h"
#include "Subject.h"

dae::ScoreComponent::ScoreComponent(GameObject* pOwner)
	: CounterComponent{ pOwner }
{
	m_pSubject = new Subject{};
	SetValue(0);
}

void dae::ScoreComponent::Increase()
{
	++m_Value;
	m_pSubject->OnNotify(m_pOwner, Event::ScoreChange);
}

void dae::ScoreComponent::Increase(int amount)
{
	m_Value += amount;
	m_pSubject->OnNotify(m_pOwner, Event::ScoreChange);
}

void dae::ScoreComponent::SetValue(int value)
{
	m_Value = value;
	m_pSubject->OnNotify(m_pOwner, Event::ScoreChange);
}

