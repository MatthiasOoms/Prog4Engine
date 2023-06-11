#pragma once
#include "PlayerState.h"
#include <glm/vec3.hpp>

namespace dae
{
	class MoveState final : public PlayerState
	{
	public:
		MoveState(PlayerComponent* pPlayer);
		virtual ~MoveState() = default;

		virtual PlayerState* HandleInput(float) override;
		virtual void Update(float) override;
		virtual void OnEnter() override;
		virtual void OnExit() override {};

	private:
		glm::vec3 m_LastPos;
		glm::vec3 m_MoveDir;
	};
}
