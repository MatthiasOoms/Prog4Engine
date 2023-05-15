#pragma once
#include "SoundSystem.h"
#include <string>

#include <SDL.h>
#include <SDL_mixer.h> 

namespace dae
{
	class SDLSoundSystem final : public SoundSystem
	{
		class SDLSoundSystemImpl;
		SDLSoundSystemImpl* pImpl;
	public:
		void Play(const sound_id id, const float volume) override;
		void Pause() override;
		void Resume() override;
		void Stop() override;
		void Load(std::string filePath) override;
		~SDLSoundSystem() override;
	};
}
