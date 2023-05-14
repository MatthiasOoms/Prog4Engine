#pragma once
#include <memory>
namespace dae
{
	class SoundSystem;
	class NullSoundSystem;

	class SoundServiceLocator final
	{
		static std::unique_ptr<SoundSystem> m_Instance;
	public:
		static SoundSystem& GetSoundSystem();
		static void RegisterSoundSystem(std::unique_ptr<SoundSystem>&& ss);
	};
}
