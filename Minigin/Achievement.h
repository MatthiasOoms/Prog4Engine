#pragma once
#include "Observer.h"

namespace dae
{
    class Achievement : public Observer
    {
    public:
        virtual void OnNotify(const GameObject& entity, Event event);
    private:
    };
}
