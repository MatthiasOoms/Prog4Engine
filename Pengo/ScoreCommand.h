#pragma once
#include <Command.h>
namespace dae
{
	class ScoreCommand final : public Command
	{
	private:
		GameObject* m_pGameObject;
	protected:
		GameObject* GetGameObject() { return m_pGameObject; }
	public:
		ScoreCommand(GameObject* pGameObject);
		virtual ~ScoreCommand() = default;
		void Execute(float elapsedSec) override;
	};
}
