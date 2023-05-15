#include "LoggingSoundSystem.h"

void dae::LoggingSoundSystem::Play(const sound_id id, const float volume)
{
	_real_ss->Play(id, volume);
	std::cout << "playing " << id << " at volume " << volume << std::endl;
}

void dae::LoggingSoundSystem::Load(const std::string& filePath)
{
	_real_ss->Load(filePath);
	std::cout << "loading " << filePath << std::endl;
}
