#pragma once
#include "SoundSystem.h"

class SDLSoundSystem final : public SoundSystem
{
public:
	void Play(const sound_id id, const float volume) override;
	void Pause() override;
	void Resume() override;
	void Stop() override;
};
