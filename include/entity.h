#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <string> 
#include "item.h" 
#include "GlobalFiles.h"
#include "inventory.h"
#include "worldMap.h"
#include "collisionManager.h"

class Entity{
private:
    Item* currentItem; 

public:
    std::string textureFile;
    sf::Texture texture;
    sf::Sprite sprite;
    Inventory inventory;
    bool forward;
    int state;
    sf::FloatRect collisionBox;
    sf::Vector2i frameSize;
    int currentFrame;
    int currentRow;
    float animationTimer;
    float frameTime;
    float attackAnimationTimer = 0.0f; 
    float attackFrameTime = 0.1f;  
    int attackFrames = 6;      
    Entity(std::string textureFile);
    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f newPosition);
    void update(float deltaTime,CollisionManager& collisionManager);
    void updateSelectedItem(sf::Event event);
    void draw(sf::RenderTarget& target);
    bool hasItem() const;
    void addItem(Item newItem);
    void setCurrentItem(Item* newItem);
    void removeCurrentItem();
    void attack();




};



#endif