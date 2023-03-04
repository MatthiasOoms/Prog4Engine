#pragma once
#include "Component.h"
#include <string>
#include <memory>

namespace dae
{
	class TextComponent;

	class FPSComponent : public UpdateComponent
	{
	public:
		FPSComponent(GameObject* pOwner);
		virtual ~FPSComponent() {};

		virtual void Update(float elapsedSec);

	private:
		TextComponent* m_pTextComponent;
	};
}

