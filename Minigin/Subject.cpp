#include "Subject.h"
#include "Observer.h"
#include "GameObject.h"

dae::Subject::Subject()
	: m_pObservers{}
{
}

dae::Subject::~Subject()
{
	for (int i{}; i < m_pObservers.size(); ++i)
	{
		delete m_pObservers[i];
		m_pObservers[i] = nullptr;
	}
}

void dae::Subject::OnNotify(Event event)
{
    for (int i{}; i < m_pObservers.size(); ++i)
    {
        m_pObservers[i]->OnNotify(event);
    }
}

void dae::Subject::addObserver(Observer* pObserver)
{
	m_pObservers.push_back(pObserver);
}

void dae::Subject::removeObserver(Observer* pObserver)
{
	m_pObservers.erase(std::find(m_pObservers.begin(), m_pObservers.end(), pObserver));
}
