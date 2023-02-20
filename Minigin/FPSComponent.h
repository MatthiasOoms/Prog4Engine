#pragma once
#include "Component.h"
class FPSComponent : public Component
{
public:
	virtual void Component::Update(float deltaTime) override;
private:
	int m_FPS;
};

