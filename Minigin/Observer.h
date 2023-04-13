#pragma once


namespace dae
{
	class GameObject;

	enum class Event
	{
		PlayerDeath,
		EnemyDeath,
		ACH_WIN_ONE_GAME
	};

	class Observer
	{
	public:
		virtual ~Observer() {};
		virtual void OnNotify(const GameObject& entity, Event event) = 0;
	};

}

