#include "SDLSoundSystem.h"

class dae::SDLSoundSystem::SDLSoundSystemImpl
{
public:
	void Play(const sound_id id, const float volume)
	{

	}

	void Pause()
	{

	}

	void Resume()
	{

	}

	void Stop()
	{

	}

	void Load(std::string filePath)
	{

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
	delete pImpl;
	pImpl = nullptr;
}
