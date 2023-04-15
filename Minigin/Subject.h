#pragma once
#include <vector>

namespace dae
{
	class GameObject;
	class Observer;
	enum class Event;

	class Subject final
	{
	private:
		std::vector<Observer*> m_pObservers;

	public:
		Subject();
		virtual ~Subject();

		void OnNotify(GameObject* obj, Event event);
		void addObserver(Observer* pObserver);
		void removeObserver(Observer* pObserver);
	};
}