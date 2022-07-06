#ifndef ENEMYEMITTERCOMPONENT_H

#include <SDL2/SDL.h>

struct EnemyEmitterComponent {
    int lastEmissionTime;

    EnemyEmitterComponent() {
        this->lastEmissionTime = SDL_GetTicks();
    }
};

#endif
