#pragma once


namespace dae
{
	class GameObject;

	enum class Event
	{
		PlayerDeath,
		EnemyDeath,
		ScoreChange,
		PlaySound,
		PauseSound,
		ResumeSound,
		StopSound,
		ChangeVolume,
		MuteSound,
		UnmuteSound
	};

	class Observer
	{
	public:
		virtual ~Observer() {};
		virtual void OnNotify(GameObject* obj, Event event) = 0;
	};

}

