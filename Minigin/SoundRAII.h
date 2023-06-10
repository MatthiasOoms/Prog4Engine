#pragma once
#include <glm/vec2.hpp>

struct Mix_Chunk;
namespace dae
{
	/**
	 * Simple RAII wrapper for a Mix_Chunk
	 */
	class SoundRAII final
	{
	public:
		Mix_Chunk* GetSound() const;
		explicit SoundRAII(Mix_Chunk* sound);
		~SoundRAII();

		SoundRAII(const SoundRAII&) = delete;
		SoundRAII(SoundRAII&&) = delete;
		SoundRAII& operator= (const SoundRAII&) = delete;
		SoundRAII& operator= (const SoundRAII&&) = delete;
	private:
		Mix_Chunk* m_pSound;
	};
}

