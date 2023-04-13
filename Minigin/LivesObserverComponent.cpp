#include "LivesObserverComponent.h"
#include "LivesComponent.h"
#include "TextComponent.h"
#include "GameObject.h"

dae::LivesObserverComponent::LivesObserverComponent(GameObject* pObj, LivesComponent* pLivesComp)
	: Component(pObj)
{
	m_pLivesComponent = pLivesComp;
}

dae::LivesObserverComponent::~LivesObserverComponent()
{
}

void dae::LivesObserverComponent::Notify(Event event)
{
	switch (event)
	{
	case dae::Event::PlayerDeath:

		// Get lives and put in text
		m_LivesText = std::to_string(m_pOwner->GetComponent<LivesComponent>()->GetLives());

		// Give text to TxtDisplay
		if (m_pOwner->HasComponent<TextComponent>() && m_LivesText.size() > 0)
		{
			m_pOwner->GetComponent<TextComponent>()->SetText(m_LivesText);
		}
		break;
	case dae::Event::EnemyDeath:
		break;
	case dae::Event::ACH_WIN_ONE_GAME:
		break;
	default:
		break;
	}
}

