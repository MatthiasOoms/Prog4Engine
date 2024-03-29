#include "SDLSoundSystem.h"
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

#include <SDL.h>
#include <SDL_mixer.h> 

class dae::SDLSoundSystem::SDLSoundSystemImpl
{
	std::vector<Mix_Chunk*> m_pSoundEffects;
	std::mutex m_SoundEffectsMutex{};

public:
	void Play(const sound_id id, const float volume)
	{
		std::jthread soundPlayerThread
		([this, id, volume]()
			{
				std::lock_guard<std::mutex> lock(m_SoundEffectsMutex);
				if (id >= m_pSoundEffects.size())
				{
					std::cerr << "Sound ID out of range: " << id << std::endl;
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
		);
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

	void Load(const std::string& filePath)
	{
		std::jthread soundLoaderThread
		([this, filePath]()
			{
				Mix_Chunk* soundEffect = Mix_LoadWAV(filePath.c_str());
				if (soundEffect == nullptr)
				{
					std::cerr << "Failed to load sound effect: " << Mix_GetError() << std::endl;
					return;
				}

				std::lock_guard<std::mutex> lock(m_SoundEffectsMutex);
				m_pSoundEffects.push_back(soundEffect);

				// TODO: Implement RAII like in the 2D Texture
				// Freeing the chunk removes from memory, using deleted sound
				// 
				// Tried, don't know how to do this correctly
				// 
				//Mix_FreeChunk(soundEffect);
			}
		);
	}

	void Cleanup()
	{
		for (auto sound : m_pSoundEffects)
		{
			Mix_FreeChunk(sound);
		}

		Mix_CloseAudio();
		Mix_Quit();
		SDL_Quit();
	}
};

dae::SDLSoundSystem::SDLSoundSystem()
{
	if (Mix_Init(SDL_INIT_AUDIO) < 0)
	{
		std::cout << "SDL_mixer initialization failed: " << SDL_GetError() << std::endl;
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		std::cout << "SDL_mixer OpenAudio failed: " << Mix_GetError() << std::endl;
	}

	pImpl = new SDLSoundSystemImpl{};
}

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

void dae::SDLSoundSystem::Load(const std::string& filePath)
{
	pImpl->Load(filePath);
}

dae::SDLSoundSystem::~SDLSoundSystem()
{
	pImpl->Cleanup();

	delete pImpl;
	pImpl = nullptr;
}
