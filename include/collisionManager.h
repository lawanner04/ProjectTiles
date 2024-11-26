#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <SFML/Graphics.hpp>
#include <string> 
#include "GlobalFiles.h"
#include "worldMap.h"

class CollisionManager
{
private:
    std::vector<sf::FloatRect> collisionBounds;

public:
    void addCollisionBounds(const sf::FloatRect& bounds);
    void addCollisionBounds(const std::vector<sf::FloatRect>& bounds);

    void checkCollision(sf::FloatRect& entityBounds, sf::Vector2f& velocity);
    sf::FloatRect getCollisionBox(const sf::Sprite& playerSprite);
    void drawDebug(sf::RenderWindow& window);
};

#endif