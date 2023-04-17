#include "AchievementsObserverComponent.h"
#include "GameObject.h"
#include "ScoreComponent.h"

void dae::AchievementsObserverComponent::OnNotify(GameObject* obj, Event event)
{
	int score{};
	switch (event)
	{
	case dae::Event::PlayerDeath:
		break;
	case dae::Event::EnemyDeath:
		break;
	case dae::Event::ScoreChange:
		if (!obj->HasComponent<ScoreComponent>())
		{
			break;
		}

		score = obj->GetComponent<ScoreComponent>()->GetScore();
		if (score >= 500)
		{
			UnlockAchievement("ACH_WIN_ONE_GAME");
		}
		break;
	default:
		break;
	}
}

void dae::AchievementsObserverComponent::UnlockAchievement(const char* id)
{
	SteamUserStats()->SetAchievement(id);
	SteamUserStats()->StoreStats();
}
