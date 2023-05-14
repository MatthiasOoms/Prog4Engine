#pragma once
#include "SoundSystem.h"

class NullSoundSystem final : public SoundSystem
{
	void Play(const sound_id, const float) override {}
	virtual void Pause() override {};
	virtual void Resume() override {};
	virtual void Stop() override {};
};

