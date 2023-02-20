#pragma once
#include "Component.h"
class VisualComponent : public Component
{
public:
	virtual void Component::Update(float deltaTime) override = 0;
	virtual void Render() const = 0;
};

