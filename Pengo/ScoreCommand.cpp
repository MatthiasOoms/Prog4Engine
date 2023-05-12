#include "ScoreCommand.h"

dae::ScoreCommand::ScoreCommand(GameObject* pGameObject)
	: Command{ }
	, m_pGameObject{ pGameObject }
{
}