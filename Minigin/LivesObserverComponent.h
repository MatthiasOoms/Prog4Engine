#pragma once
#include "Component.h"
#include "Observer.h"

namespace dae
{
	class LivesObserverComponent final : public Component, public Observer
	{
		void Notify(Event event);
	};
}
