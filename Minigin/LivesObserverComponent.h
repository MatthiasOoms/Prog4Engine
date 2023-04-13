#pragma once
#include <string>
#include "Component.h"
#include "Observer.h"

namespace dae
{
	class LivesObserverComponent final : public Component, public Observer
	{
	public:
		LivesObserverComponent(GameObject* pObj, LivesComponent* pLivesComp);
		virtual ~LivesObserverComponent();

		void Notify(Event event);

	private:
		std::string m_LivesText;
		LivesComponent* m_pLivesComponent;
	};
}
