#include "Subject.h"
#include "Observer.h"
#include "GameObject.h"

void dae::Subject::Notify(const GameObject& object, Event event)
{
    for (int i{}; i < m_pObservers.size(); ++i)
    {
        m_pObservers[i]->OnNotify(object, event);
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
