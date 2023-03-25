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

void dae::MoveCommand::Execute()
{
	// TODO
	// GetGameObject()->SetLocalPosition(GetGameObject()->GetTransform().GetLocalPosition());
}
