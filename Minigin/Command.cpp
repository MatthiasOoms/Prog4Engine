#include "Command.h"
#include "GameObject.h"

dae::Command::Command(GameObject* pGameObject)
{
	m_pGameObject = pGameObject;
}

dae::Command::~Command()
{
	delete m_pGameObject;
	m_pGameObject = nullptr;
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
