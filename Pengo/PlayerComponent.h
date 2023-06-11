#pragma once
#include "Component.h"

namespace dae
{
	class PlayerState;
	class GameObject;

	class PlayerComponent final : public Component
	{
	private:
		PlayerState* m_pState;

	public:
		PlayerComponent(GameObject* pOwner);
		virtual ~PlayerComponent();

		void HandleInput(float);
		void Update(float);
		GameObject* GetOwner() const;
	};
}
