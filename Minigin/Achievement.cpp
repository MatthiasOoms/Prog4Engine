#include "Achievement.h"

void dae::Achievement::OnNotify(const GameObject& entity, Event event)
{
    switch (event)
    {
    case Event::PlayerDeath:
        entity; // To prevent "not used" complaint
        break;
    default:
        break;
    }
}
