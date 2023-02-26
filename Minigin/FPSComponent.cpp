#include "FPSComponent.h"
#include "GameObject.h"
#include "TextComponent.h"

void dae::FPSComponent::Update(float elapsedSec, const GameObject* obj)
{
	if (m_pTextComponent != nullptr)
	{
		m_pTextComponent->SetText(std::to_string(int(1.f/elapsedSec)));
	}
	else
	{
		m_pTextComponent = obj->GetComponent<dae::TextComponent>();
	}
}
