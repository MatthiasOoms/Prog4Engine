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
		FPSComponent() = default;
		virtual ~FPSComponent() {};

		virtual void Update(float elapsedSec, const GameObject* obj);

	private:
		TextComponent* m_pTextComponent;
	};
}

