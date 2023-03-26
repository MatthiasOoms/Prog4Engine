#include "Command.h"
#include "GameObject.h"
#include <iostream>

dae::Command::Command(GameObject* pGameObject)
{
	m_pGameObject = pGameObject;
}

dae::Command::~Command()
{
}

dae::MoveCommand::MoveCommand(GameObject* pGameObject, glm::vec3 dir, float speed)
	: Command{pGameObject}
	, m_MoveDir{dir}
	, m_MoveSpeed{speed}
{
}

void dae::MoveCommand::Execute(float elapsedSec)
{
	GetGameObject()->SetLocalPosition(GetGameObject()->GetTransform().GetLocalPosition() + (m_MoveDir * m_MoveSpeed * elapsedSec));
}
