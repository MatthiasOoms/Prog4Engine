#pragma once


namespace dae
{
	class GameObject;

	enum class Event
	{
		PlayerDeath,
		EnemyDeath,
		ScoreChange,
		ACH_WIN_ONE_GAME
	};

	class Observer
	{
	public:
		virtual ~Observer() {};
		virtual void OnNotify(GameObject* obj, Event event) = 0;
	};

}

