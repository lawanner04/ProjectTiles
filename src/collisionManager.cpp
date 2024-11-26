#include "collisionManager.h"

void CollisionManager::addCollisionBounds(const sf::FloatRect& bounds){
    collisionBounds.push_back(bounds);
}

void CollisionManager::addCollisionBounds(const std::vector<sf::FloatRect>& bounds){
    collisionBounds.insert(collisionBounds.end(), bounds.begin(), bounds.end());
}

void CollisionManager::checkCollision(sf::FloatRect& entityBounds, sf::Vector2f& velocity) {
    for (const auto& bounds : collisionBounds) {
        if (entityBounds.intersects(bounds)) {
            // Determine the depth of the overlap
            float overlapX = std::min(entityBounds.left + entityBounds.width, bounds.left + bounds.width) 
                            - std::max(entityBounds.left, bounds.left);
            float overlapY = std::min(entityBounds.top + entityBounds.height, bounds.top + bounds.height) 
                            - std::max(entityBounds.top, bounds.top);

            // Correct velocity based on the smallest overlap (axis of least penetration)
            if (overlapX < overlapY) {
                // Collision on the X-axis
                if (entityBounds.left < bounds.left) {
                    velocity.x = std::min(velocity.x, 0.f); // Prevent moving right into the boundary
                } else {
                    velocity.x = std::max(velocity.x, 0.f); // Prevent moving left into the boundary
                }
            } else {
                // Collision on the Y-axis
                if (entityBounds.top < bounds.top) {
                    velocity.y = std::min(velocity.y, 0.f); // Prevent moving down into the boundary
                } else {
                    velocity.y = std::max(velocity.y, 0.f); // Prevent moving up into the boundary
                }
            }
        }
    }
}

sf::FloatRect CollisionManager::getCollisionBox(const sf::Sprite& playerSprite) {
    sf::FloatRect spriteBounds = playerSprite.getGlobalBounds();

    // Define the collision box at the player's feet
    float collisionBoxWidth = spriteBounds.width * 0.25f;  // Smaller width
    float collisionBoxHeight = spriteBounds.height * 0.25f; // Small height at the bottom
    float collisionBoxLeft = spriteBounds.left + (spriteBounds.width - collisionBoxWidth) / 2.f;
    float collisionBoxTop = spriteBounds.top + spriteBounds.height * 0.8f; // Positioned at the bottom

    return sf::FloatRect(collisionBoxLeft, collisionBoxTop, collisionBoxWidth, collisionBoxHeight);
}



void CollisionManager::drawDebug(sf::RenderWindow& window){
    for (const auto& bounds : collisionBounds){
        sf::RectangleShape rect(sf::Vector2f(bounds.width, bounds.height));
        rect.setPosition(bounds.left, bounds.top);
        rect.setFillColor(sf::Color::Transparent);
        rect.setOutlineColor(sf::Color::Red);
        rect.setOutlineThickness(1.f);
        window.draw(rect);
    }
}

