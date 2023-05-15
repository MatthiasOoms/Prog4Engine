#include "SDLSoundSystem.h"
#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

class dae::SDLSoundSystem::SDLSoundSystemImpl
{
	std::vector<Mix_Chunk*> m_pSoundEffects;
	std::mutex m_SoundEffectsMutex;
public:
	SDLSoundSystem::SDLSoundSystemImpl()
	{
		if (SDL_Init(SDL_INIT_AUDIO) < 0)
		{
			std::cout << "SDL initialization failed: " << SDL_GetError() << std::endl;
		}

		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		{
			std::cout << "SDL_mixer initialization failed: " << Mix_GetError() << std::endl;
		}
	}

	void Play(const sound_id id, const float volume)
	{
		if (id >= m_pSoundEffects.size()) 
		{
			std::cerr << "Invalid sound ID: " << id << std::endl;
			return;
		}

		Mix_Chunk* soundEffect{ m_pSoundEffects[id] }; // Put current sound in there

		if (soundEffect == nullptr) 
		{
			std::cerr << "Invalid sound ID: " << id << std::endl;
			return;
		}

		int channel = Mix_PlayChannel(-1, soundEffect, 0);
		if (channel == -1) 
		{
			std::cerr << "Failed to play sound: " << Mix_GetError() << std::endl;
			return;
		}

		Mix_Volume(channel, static_cast<int>(volume * MIX_MAX_VOLUME));
	}

	void Pause()
	{
		Mix_Pause(-1);
	}

	void Resume()
	{
		Mix_Resume(-1);
	}

	void Stop()
	{
		Mix_HaltChannel(-1);
	}

	void Load(std::string filePath)
	{
		std::jthread soundLoaderThread([this, filePath]()
			{
				Mix_Chunk* soundEffect = Mix_LoadWAV(filePath.c_str());
				if (soundEffect == nullptr)
				{
					std::cerr << "Failed to load sound effect: " << Mix_GetError() << std::endl;
					return;
				}

				std::lock_guard<std::mutex> lock(m_SoundEffectsMutex);
				m_pSoundEffects.push_back(soundEffect);

				Mix_FreeChunk(soundEffect);
			});
	}

	void Cleanup()
	{
		Mix_CloseAudio();
		Mix_Quit();
		SDL_Quit();
	}
};

void dae::SDLSoundSystem::Play(const sound_id id, const float volume)
{
	pImpl->Play(id, volume);
}

void dae::SDLSoundSystem::Pause()
{
	pImpl->Pause();
}

void dae::SDLSoundSystem::Resume()
{
	pImpl->Resume();
}

void dae::SDLSoundSystem::Stop()
{
	pImpl->Stop();
}

void dae::SDLSoundSystem::Load(std::string filePath)
{
	pImpl->Load(filePath);
}

dae::SDLSoundSystem::~SDLSoundSystem()
{
	pImpl->Cleanup();

	delete pImpl;
	pImpl = nullptr;
}
