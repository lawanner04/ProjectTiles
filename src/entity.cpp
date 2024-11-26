#include "entity.h"

Entity::Entity(std::string textureFile){
    frameSize = sf::Vector2i(48,48);
    currentFrame = 0;
    animationTimer = 0.0f;
    frameTime = 0.1f;
    forward = true;
    state = 0;
    currentRow = state;

    
    collisionBox = sprite.getLocalBounds();
    textureFile = basePath + textureFile;
    texture.loadFromFile(textureFile);
    sprite.setTexture(texture);
    sprite.setScale(1,1);
    sprite.setOrigin(frameSize.x / 2, frameSize.y / 2);
    sprite.setTextureRect(sf::IntRect(0, 0, frameSize.x, frameSize.y));
    sprite.setPosition(100, 100);
    currentItem = nullptr; 
}

void Entity::update(float deltaTime, CollisionManager& collisionManager){
    float fSpeed = 120.0f;
    float scale = 1;
    animationTimer += deltaTime;

    if(forward){
        sprite.setScale(abs(sprite.getScale().x),abs(sprite.getScale().y));
    }
    else{
        sprite.setScale(-1*abs(sprite.getScale().x),abs(sprite.getScale().y));
    }

    if (state == 2) {
        attackAnimationTimer += deltaTime;
        if (attackAnimationTimer >= attackFrameTime) {
            attackAnimationTimer = 0.0f;
            currentFrame++;
            if (currentFrame >= attackFrames) {
                state = 0;         
                currentFrame = 0;  
            }
        }
        sprite.setTextureRect(sf::IntRect(currentFrame * frameSize.x, state * frameSize.y, frameSize.x, frameSize.y));
        return; 
    }

    if (animationTimer >= frameTime) {
        animationTimer = 0.0f;
        currentFrame = (currentFrame + 1) % 6;
        sprite.setTextureRect(sf::IntRect(currentFrame * frameSize.x, state * frameSize.y, frameSize.x, frameSize.y));
    }

    if (currentItem != nullptr) {
        if (forward) {
            currentItem->setItemSpriteScale(scale, scale);
        } else {
            currentItem->setItemSpriteScale(-scale, scale);
        }
    }
    currentRow = state;

    sf::Vector2f vRequestedMvmt(0.0,0.0);

    collisionBox = collisionManager.getCollisionBox(sprite);
    collisionManager.checkCollision(collisionBox, vRequestedMvmt);

    float fLength = sqrt(vRequestedMvmt.x * vRequestedMvmt.x + vRequestedMvmt.y * vRequestedMvmt.y);
    if (fLength != 0.0f) {
        vRequestedMvmt /= fLength;  // Normalize only if needed
    }


    if (currentItem != nullptr) {
        currentItem->setItemPosition(sprite.getPosition());
    }

    sprite.move(vRequestedMvmt * deltaTime * fSpeed);
}

void Entity::attack(){
    attackAnimationTimer = 0.0f; // Reset attack timer
    currentFrame = 0;  
    if(currentItem!=nullptr){    
        if(currentItem->getItemType()=="sword") {    // Start attack animation from the first frame
            state = 2;  
        }    
    }
}

sf::Vector2f Entity::getPosition(){
    return sprite.getPosition();
}

void Entity::setPosition(sf::Vector2f newPos){
    sprite.setPosition(newPos);
}

void Entity::draw(sf::RenderTarget& target){
    target.draw(sprite);
    if (currentItem != nullptr) {
        currentItem->drawItem(currentFrame,state,target);
    }
}

void Entity::addItem(Item newItem){
    inventory.addItem(newItem);
}

void Entity::setCurrentItem(Item* newItem) {
    if (newItem != nullptr) {
        currentItem = newItem;
        currentItem->setItemSpriteScale(1,1);;
    }
}

void Entity::removeCurrentItem() {
    currentItem = nullptr; 
}

