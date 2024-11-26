#ifndef PLAYER_H 
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <string> 
#include "item.h" 
#include "GlobalFiles.h"
#include "inventory.h"
#include "worldMap.h"
#include "collisionManager.h"
#include "enemy.h"

class Player {
private:
    Item* currentItem; 
    
public:
    std::string playerTextureFile;
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    Inventory playerInventory;
    float myScale = 1;
    bool forward;
    bool running;
    int state;

    sf::FloatRect collisionBox;
    bool onGround = false;

    sf::Vector2i frameSize;
    int totalFrames;
    int currentFrame;
    int currentRow;
    float animationTimer;
    float frameTime;
    float attackAnimationTimer = 0.0f; // Timer for the attack animation
    float attackFrameTime = 0.1f;  // Time per attack frame
    int attackFrames = 6;        // Total attack frames

    Player(std::string myPlayerTextureFile);
    sf::Vector2f getPlayerPosition();
    void setPlayerPosition(sf::Vector2f newPosition);
    void updatePlayer(float deltaTime,CollisionManager& collisionManager);
    void updatePlayerHotbar();
    void updatePlayerSelectedItem(sf::Event event);
    void drawPlayer(sf::RenderWindow& myWindow);
    void drawPlayerHotbar(sf::RenderWindow& myWindow);
    bool hasItem() const;
    void addItem(Item newItem);
    void setCurrentItem(Item* newItem);
    void removeCurrentItem();

    void playerAttack();
    void playerDamageEnemy(Enemy enemy);
};

#endif
