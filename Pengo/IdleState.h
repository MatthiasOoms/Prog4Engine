#pragma once
#include "PlayerState.h"
#include <glm/vec3.hpp>

namespace dae
{
	class IdleState final : public PlayerState
	{
	public:
		IdleState(PlayerComponent* pPlayer);
		virtual ~IdleState() = default;

		virtual PlayerState* HandleInput(float) override;
		virtual void Update(float) override {};
		virtual void OnEnter() override {};
		virtual void OnExit() override {};

	private:
		glm::vec3 m_LastPos;
	};
}
