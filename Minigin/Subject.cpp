#include "Subject.h"
#include "Observer.h"
#include "GameObject.h"

dae::Subject::Subject()
	: m_pObservers{}
{
}

dae::Subject::~Subject()
{
}

void dae::Subject::OnNotify(GameObject* obj, Event event)
{
    for (int i{}; i < m_pObservers.size(); ++i)
    {
        m_pObservers[i]->OnNotify(obj, event);
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
