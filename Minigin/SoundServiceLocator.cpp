#include "SoundServiceLocator.h"
#include "NullSoundSystem.h"

SoundSystem& SoundServiceLocator::GetSoundSystem()
{
	return *m_Instance;
}

void SoundServiceLocator::RegisterSoundSystem(std::unique_ptr<SoundSystem>&& ss)
{
	if (ss == nullptr)
	{
		m_Instance = std::make_unique<NullSoundSystem>();
	}
	else
	{
		std::move(ss);
	}
}
