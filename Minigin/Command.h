#pragma once
#include <glm/glm.hpp>

namespace dae
{
	class GameObject;

	class Command
	{
	protected:
		GameObject* GetGameObject() const { return m_pGameObject; }
	public:
		explicit Command(GameObject* pGameObject);
		virtual ~Command();
		virtual void Execute() = 0;
	private:
		GameObject* m_pGameObject;
	};

	class MoveCommand : public Command
	{
	private:
		glm::vec3 m_MoveDir;
		float m_MoveSpeed;
		float m_Acceleration;
	public:
		void Execute() override;
	};
}

