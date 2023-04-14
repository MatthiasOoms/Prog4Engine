#pragma once
#include <string>
#include "Component.h"
#include "Observer.h"

namespace dae
{
	class GameObject;
	class LivesComponent;

	class LivesObserverComponent final : public Component, public Observer
	{
	public:
		virtual void Update(float) override {};
		virtual void Render(float) const override {};

		LivesObserverComponent(GameObject* pObj);
		virtual ~LivesObserverComponent();

		virtual void OnNotify(Event event) override;
		void SetLivesComponent(LivesComponent* pLivesComp);
		void UpdateText();

	private:
		std::string m_LivesText;
		LivesComponent* m_pLivesComponent;
	};
}
