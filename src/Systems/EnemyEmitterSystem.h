#ifndef MAKEENEMIESSYSTEM_H
#define MAKEENEMIESSYSTEM_H

#include <SDL2/SDL.h>
#include "../Logger/Logger.h"

class EnemyEmitterSystem: public System {
    public:
        EnemyEmitterSystem() {
            RequireComponent<EnemyEmitterComponent>();
        }
        
        void Update(std::unique_ptr<Registry>& registry) {
            for (auto entity: GetSystemEntities()) {
                auto& enemyEmitter = entity.GetComponent<EnemyEmitterComponent>();

                int repeatFrequency = rand()%(4000-2000 + 1) + 2000;

                if (SDL_GetTicks() - enemyEmitter.lastEmissionTime > repeatFrequency) 
                {
                    int rng = rand()%(750-50 + 1) + 50;

                    Entity enemy = registry->CreateEntity();
                    enemy.Group("enemies");
                    enemy.AddComponent<TransformComponent>(glm::vec2(static_cast<double>(rng), 10.0), glm::vec2(1.0, 1.0), 0.0);
                    enemy.AddComponent<RigidBodyComponent>(glm::vec2(0.0, 50.0));
                    enemy.AddComponent<SpriteComponent>("enemy-image", 32, 32, 1);
                    enemy.AddComponent<AnimationComponent>(4, 15, true);
                    enemy.AddComponent<BoxColliderComponent>(32, 32);
                    enemy.AddComponent<HealthComponent>(100);
                
                    enemyEmitter.lastEmissionTime = SDL_GetTicks();
                }
            }
        }
};

#endif
