#include "LivesObserverComponent.h"
#include "LivesComponent.h"
#include "TextComponent.h"
#include "GameObject.h"

dae::LivesObserverComponent::LivesObserverComponent(GameObject* pObj)
	: Component(pObj)
	, m_pLivesComponent{ nullptr }
{
}

dae::LivesObserverComponent::~LivesObserverComponent()
{
	m_pOwner = nullptr;
	m_pLivesComponent = nullptr;
}

void dae::LivesObserverComponent::OnNotify(Event event)
{
	switch (event)
	{
	case dae::Event::PlayerDeath:
		UpdateText();
		break;
	case dae::Event::EnemyDeath:
		break;
	case dae::Event::ACH_WIN_ONE_GAME:
		break;
	default:
		break;
	}
}

void dae::LivesObserverComponent::SetLivesComponent(LivesComponent* pLivesComp)
{
	m_pLivesComponent = pLivesComp;
	UpdateText();
}

void dae::LivesObserverComponent::UpdateText()
{
	// Get lives and put in text
	if (m_pLivesComponent)
	{
		m_LivesText = std::to_string(m_pLivesComponent->GetLives());
	}

	// Give text to TxtDisplay
	if (m_pOwner->HasComponent<TextComponent>() && m_LivesText.size() > 0)
	{
		m_pOwner->GetComponent<TextComponent>()->SetText(m_LivesText);
	}
}

