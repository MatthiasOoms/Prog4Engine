#include "SoundRAII.h"
#include <SDL_mixer.h>

dae::SoundRAII::~SoundRAII()
{
	Mix_FreeChunk(m_pSound);
}

Mix_Chunk* dae::SoundRAII::GetSound() const
{
	return m_pSound;
}

dae::SoundRAII::SoundRAII(Mix_Chunk* sound)
{
	m_pSound = sound;
}

