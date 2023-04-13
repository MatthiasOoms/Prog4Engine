#include "LivesObserverComponent.h"
#include "LivesComponent.h"
#include "GameObject.h"
#include <string>

void dae::LivesObserverComponent::Notify(Event event)
{
	switch (event)
	{
	case dae::Event::PlayerDeath:
		std::string temp = std::to_string(m_pOwner->GetComponent<LivesComponent>()->SetLives())
		break;
	case dae::Event::EnemyDeath:
		break;
	case dae::Event::ACH_WIN_ONE_GAME:
		break;
	default:
		break;
	}
}
