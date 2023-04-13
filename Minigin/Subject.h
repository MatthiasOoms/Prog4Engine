#pragma once
#include <vector>

namespace dae
{
	class Observer;

	class Subject
	{
	private:
		std::vector<Observer*> m_pObservers;

	protected:
		void Notify(const GameObject& object, Event event);

	public:
		void addObserver(Observer* pObserver);
		void removeObserver(Observer* pObserver);
	};
}
