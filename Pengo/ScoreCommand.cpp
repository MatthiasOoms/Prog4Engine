#include "ScoreCommand.h"
#include "GameObject.h"
#include "ScoreComponent.h"

dae::ScoreCommand::ScoreCommand(GameObject* pGameObject)
	: Command{ }
	, m_pGameObject{ pGameObject }
{
}

void dae::ScoreCommand::Execute(float)
{
	if (GetGameObject()->HasComponent<ScoreComponent>())
	{
		GetGameObject()->GetComponent<ScoreComponent>()->Increase(100);
	}
}
