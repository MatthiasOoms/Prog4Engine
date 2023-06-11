#pragma once

namespace dae
{
	class PlayerComponent;

	class PlayerState
	{
	public:
		PlayerState(PlayerComponent* pPlayer);
		~PlayerState();
		virtual PlayerState* HandleInput(float) { return nullptr; };
		virtual void Update(float) {};
		virtual void OnEnter() {};
		virtual void OnExit() {};

	protected:
		PlayerComponent* m_pPlayer;
	};
}
