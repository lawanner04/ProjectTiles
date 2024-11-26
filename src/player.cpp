#include "player.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <cmath> 

Player::Player(std::string myPlayerTextureFile) {
    frameSize = sf::Vector2i(48,48);
    totalFrames = 6;
    currentFrame = 0;
    animationTimer = 0.0f;
    frameTime = 0.1f;
    forward = true;
    running = false;
    state = 0;
    currentRow = state;

    
    collisionBox = playerSprite.getLocalBounds();
    playerTextureFile = basePath + myPlayerTextureFile;
    playerTexture.loadFromFile(playerTextureFile);
    playerSprite.setTexture(playerTexture);
    playerSprite.setScale(myScale, myScale);
    playerSprite.setOrigin(frameSize.x / 2, frameSize.y / 2);
    playerSprite.setTextureRect(sf::IntRect(0, 0, frameSize.x, frameSize.y));
    playerSprite.setPosition(300, 300);
    currentItem = nullptr;
}

void Player::updatePlayer(float deltaTime, CollisionManager& collisionManager) {
    float fSpeed = 120.0f;
    float playerSpriteScale = myScale;
    animationTimer += deltaTime;
    updatePlayerHotbar();
    if (state == 2) {
        // Handle attack animation
        attackAnimationTimer += deltaTime;
        if (attackAnimationTimer >= attackFrameTime) {
            attackAnimationTimer = 0.0f;
            currentFrame++;
            if (currentFrame >= attackFrames) {
                state = 0;          // Return to idle state
                currentFrame = 0;   // Reset frame
            }
        }
        playerSprite.setTextureRect(sf::IntRect(currentFrame * frameSize.x, state * frameSize.y, frameSize.x, frameSize.y));
        return; // Skip movement while updating attack
    }

    if (animationTimer >= frameTime) {
        animationTimer = 0.0f;
        currentFrame = (currentFrame + 1) % totalFrames;
        playerSprite.setTextureRect(sf::IntRect(currentFrame * frameSize.x, state * frameSize.y, frameSize.x, frameSize.y));
    }

    if (currentItem != nullptr) {
        if (forward) {
            currentItem->setItemSpriteScale(playerSpriteScale, playerSpriteScale);
        } else {
            currentItem->setItemSpriteScale(-playerSpriteScale, playerSpriteScale);
        }
    }

    sf::Vector2f vRequestedPlayerMvmt(0.0f, 0.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        vRequestedPlayerMvmt += sf::Vector2f(0.0f, -1.0f);
        state = 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        vRequestedPlayerMvmt += sf::Vector2f(-1.0f, 0.0f);
        playerSprite.setScale(-playerSpriteScale, playerSpriteScale);
        if (currentItem != nullptr) {
            currentItem->setItemSpriteScale(-playerSpriteScale, playerSpriteScale);
        }
        forward = false;
        state = 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        vRequestedPlayerMvmt += sf::Vector2f(0.0f, 1.0f);
        state = 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        vRequestedPlayerMvmt += sf::Vector2f(1.0f, 0.0f);
        playerSprite.setScale(playerSpriteScale, playerSpriteScale);
        if (currentItem != nullptr) {
            currentItem->setItemSpriteScale(playerSpriteScale, playerSpriteScale);
        }
        forward = true;
        state = 1;
    }

    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) &&
        !sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
        !sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
        !sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        state = 0;
    }
    currentRow = state;


    collisionBox = collisionManager.getCollisionBox(playerSprite);
    collisionManager.checkCollision(collisionBox, vRequestedPlayerMvmt);

    float fLength = sqrt(vRequestedPlayerMvmt.x * vRequestedPlayerMvmt.x + vRequestedPlayerMvmt.y * vRequestedPlayerMvmt.y);
    if (fLength != 0.0f) {
        vRequestedPlayerMvmt /= fLength;  // Normalize only if needed
    }


    if (currentItem != nullptr) {
        currentItem->setItemPosition(playerSprite.getPosition());
    }

    playerSprite.move(vRequestedPlayerMvmt * deltaTime * fSpeed); // Apply the movement
}



void Player::updatePlayerHotbar() {
    playerInventory.updateHotbar(getPlayerPosition());
}
void Player::updatePlayerSelectedItem(sf::Event event) {
    playerInventory.updateSelectedItemID(event);
    if (playerInventory.selectedItemID >= 0 && playerInventory.selectedItemID < playerInventory.inventoryItems.size() &&
    playerInventory.inventoryItems[playerInventory.selectedItemID] != nullptr) {
    if(event.type == sf::Event::MouseWheelScrolled){
        currentItem = playerInventory.inventoryItems[playerInventory.selectedItemID]->clone();
    }
    } else {
        currentItem = nullptr; 
    }
    
}

void Player::playerAttack(){
    attackAnimationTimer = 0.0f; // Reset attack timer
    currentFrame = 0;  
    if(currentItem!=nullptr){    
        if(currentItem->getItemType()=="sword") {    // Start attack animation from the first frame
            state = 2;  
        }    
    }

}

sf::Vector2f Player::getPlayerPosition() {
    return playerSprite.getPosition();
}

void Player::setPlayerPosition(sf::Vector2f newPosition) {
    playerSprite.setPosition(newPosition);
}

void Player::drawPlayer(sf::RenderWindow& myWindow) {

    myWindow.draw(playerSprite);
    if (currentItem != nullptr) {
        currentItem->drawItem(currentFrame,state,myWindow);
    }
}

void Player::drawPlayerHotbar(sf::RenderWindow& myWindow) {
    playerInventory.displayHotbar(myWindow);
}

bool Player::hasItem() const {
    return currentItem != nullptr;  
}

void Player::addItem(Item newItem) {
    playerInventory.addItem(newItem);
}

void Player::setCurrentItem(Item* newItem) {
    if (newItem != nullptr) {
        currentItem = newItem;
        currentItem->setItemSpriteScale(myScale,myScale);;
    }
}

void Player::removeCurrentItem() {
    currentItem = nullptr; 
}
