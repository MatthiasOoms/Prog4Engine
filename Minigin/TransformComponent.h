#pragma once
#include "Component.h"
#include <glm/glm.hpp>

namespace dae
{
	class GameObject;

	class TransformComponent : public Component
	{
	public:
		TransformComponent(GameObject* pOwner);
		~TransformComponent();

		virtual void Update(float) override {};
		virtual void Render(float) const override {};

		const glm::vec3& GetPosition() const { return m_position; }
		void SetPosition(float x, float y, float z);
	private:
		glm::vec3 m_position;
	};
}
