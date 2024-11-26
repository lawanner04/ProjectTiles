#ifndef ENEMY_H
#define ENEMY_H
#include "entity.h"
#include "player.h"
#include <SFML/Graphics.hpp>

class Enemy : public Entity {
public:

    int enemyHealth;

    Enemy(std::string textureFile);
    void moveEnemy(Player& player,float deltaTime, CollisionManager& collisionManager);
    void drawHealth(sf::RenderTarget& target);

    void editHealth(int deltaHealth);
};


#endif