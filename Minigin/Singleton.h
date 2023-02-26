#pragma once
namespace dae
{
	template <typename Comp>
	class Singleton
	{
	public:
		static Comp& GetInstance()
		{
			static Comp instance{};
			return instance;
		}

		virtual ~Singleton() = default;
		Singleton(const Singleton& other) = delete;
		Singleton(Singleton&& other) = delete;
		Singleton& operator=(const Singleton& other) = delete;
		Singleton& operator=(Singleton&& other) = delete;

	protected:
		Singleton() = default;
	};
}