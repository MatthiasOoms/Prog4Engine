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

		virtual void OnNotify(GameObject* obj, Event event) override;
		void UpdateText(GameObject* obj);

	private:
		std::string m_ScoreText;
	};
}
