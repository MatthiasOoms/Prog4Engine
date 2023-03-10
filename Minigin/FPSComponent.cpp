#include "FPSComponent.h"
#include "GameObject.h"
#include "TextComponent.h"

dae::FPSComponent::FPSComponent(GameObject* pOwner)
	: UpdateComponent(pOwner)
	, m_pTextComponent{ nullptr }
{
}

void dae::FPSComponent::Update(float elapsedSec)
{
	if (m_pTextComponent != nullptr)
	{
		m_pTextComponent->SetText(std::to_string(int(1.f/elapsedSec)));
	}
	else
	{
		// Downside: Will try to get TextComponent every frame if there is none
		m_pTextComponent = m_pOwner->GetComponent<dae::TextComponent>();
	}
}
