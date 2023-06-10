#include "CounterComponent.h"
#include "Subject.h"

dae::CounterComponent::CounterComponent(GameObject* pOwner)
	: Component(pOwner)
	, m_Value{}
	, m_pSubject{}
{
}

dae::CounterComponent::~CounterComponent()
{
	delete m_pSubject;
	m_pSubject = nullptr;
}

void dae::CounterComponent::AddObserver(Observer* pObserver)
{
	m_pSubject->AddObserver(pObserver);
}

int dae::CounterComponent::GetValue() const
{
	return m_Value;
}
