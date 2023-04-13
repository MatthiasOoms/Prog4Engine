#pragma once
#include "Observer.h"

namespace dae
{
    class Achievement final : public Observer
    {
    public:
        virtual void OnNotify(const GameObject& entity, Event event);
    private:
    };
}
