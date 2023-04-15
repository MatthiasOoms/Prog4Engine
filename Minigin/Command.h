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
	public:
		explicit Command();
		virtual ~Command();
		virtual void Execute(float) = 0;
	};

	class MoveCommand final : public Command
	{
	private:
		GameObject* m_pGameObject;
		glm::vec3 m_MoveDir;
		float m_MoveSpeed;
		//float m_Acceleration; // Not present in my game
	protected:
		GameObject* GetGameObject() { return m_pGameObject; }
	public:
		MoveCommand(GameObject* pGameObject, glm::vec3 dir, float speed);
		virtual ~MoveCommand() = default;
		void Execute(float elapsedSec) override;
	};

	/*class KillCommand final : public Command
	{
	private:
		GameObject* m_pGameObject;
	protected:
		GameObject* GetGameObject() { return m_pGameObject; }
	public:
		KillCommand(GameObject* pGameObject);
		virtual ~KillCommand() = default;
		void Execute(float elapsedSec) override;
	};*/
}

