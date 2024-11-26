#include "enemy.h"

Enemy::Enemy(std::string textureFile):Entity(textureFile){

}

 void Enemy::moveEnemy(Player& player, float deltaTime, CollisionManager& collisionManager){
    sf::Vector2f playerDirection = getPosition()-player.getPlayerPosition();
    float length = sqrt(playerDirection.x*playerDirection.x+playerDirection.y*playerDirection.y);
    sf::Vector2f nPlayerDirection;

    if(playerDirection.x<0){
        forward = true;
    }
    else{
        forward = false;
    }
    if(length!=0){
    nPlayerDirection = sf::Vector2f(-playerDirection.x/length,-playerDirection.y/length);
    }
    if(length>0){
        state = 1;
    }
    else{
        state = 0;
    }
    float fSpeed = 60.0f;

    if(length<30){
        attack();
    }


    collisionBox = collisionManager.getCollisionBox(sprite);
    collisionManager.checkCollision(collisionBox, nPlayerDirection);

    sprite.move(nPlayerDirection*deltaTime*fSpeed);


}