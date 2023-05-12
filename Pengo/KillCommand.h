#pragma once
#include <Command.h>

namespace dae
{
	class KillCommand final : public Command
	{
	private:
		GameObject* m_pGameObject;
	protected:
		GameObject* GetGameObject() { return m_pGameObject; }
	public:
		KillCommand(GameObject* pGameObject);
		virtual ~KillCommand() = default;
		void Execute(float elapsedSec) override;
	};
}
