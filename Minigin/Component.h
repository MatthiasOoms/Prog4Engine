#pragma once
class Component
{
public:

	Component() = default;
	virtual ~Component() = 0;

	virtual void Update(float deltaTime) = 0;
	virtual void FixedUpdate([[maybe_unused]] float deltaTime) {}; // Not pure virtual so not needed to override
};

