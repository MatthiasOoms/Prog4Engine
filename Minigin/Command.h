#pragma once
#include <glm/glm.hpp>

namespace dae
{
	class GameObject;

	class Command
	{
				// TODO: Check feedback
				// Not every Command runs on a GameObject, it shouldn't be necessary
				// Could make a GameObjectCommand, could make Commands for certain Components
				// Should also be a command that doesn't need a GameObject
				//
				// Made MoveCommand final, added virtual destructor
	protected:
		GameObject* GetGameObject() const { return m_pGameObject; }
	public:
		explicit Command(GameObject* pGameObject);
		virtual ~Command();
		virtual void Execute(float) = 0;
	private:
		GameObject* m_pGameObject;
	};

	class MoveCommand final : public Command
	{
	private:
		glm::vec3 m_MoveDir;
		float m_MoveSpeed;
		//float m_Acceleration; // Not present in my game
	public:
		MoveCommand(GameObject* pGameObject, glm::vec3 dir, float speed);
		virtual ~MoveCommand() = default;
		void Execute(float elapsedSec) override;
	};
}

