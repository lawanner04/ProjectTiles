#include "item.h"

Item::Item() {}

Item::Item(std::string type, std::string itemTextureFile,std::string itemIconFile) {
    frameSize = sf::Vector2i(48,48);
    itemType = type;
    itemTexture.loadFromFile(itemTextureFile);
    itemIconTexture.loadFromFile(itemIconFile);
    itemSprite.setTexture(itemTexture);
    iconSprite.setTexture(itemIconTexture);
    itemSprite.setScale(itemScale, itemScale);
    itemSprite.setOrigin(frameSize.x / 2, frameSize.y / 2);
    itemSprite.setTextureRect(sf::IntRect(0, 0, frameSize.x, frameSize.y));
    itemSprite.setPosition(100, 100);

}

Item* Item::clone() const {
    return new Item(*this); 
}

sf::Sprite Item::getItemSprite() {
    return itemSprite;
}

void Item::setItemSpriteScale(float xScale, float yScale) {
    itemSprite.setScale(xScale, yScale);
}

void Item::setIconSpriteScale(float xScale, float yScale) {
    iconSprite.setScale(xScale, yScale);
}

void Item::setItemType(const std::string& newItemType) {
    itemType = newItemType;
}

std::string Item::getItemType(){
    return itemType;
}

void Item::drawItem(int frame,int state,sf::RenderTarget& target){
    itemSprite.setTextureRect(sf::IntRect(frame * frameSize.x, state*frameSize.y, frameSize.x, frameSize.y));
    target.draw(itemSprite);
}

void Item::drawIcon(sf::RenderWindow& myWindow) {
    myWindow.draw(iconSprite);
}

void Item::setItemTexture(sf::Texture newTexture) {
    itemTexture = newTexture;
}

sf::Vector2f Item::getItemPosition() {
    return itemSprite.getPosition();
}

void Item::setItemPosition(sf::Vector2f newPosition) {
    itemSprite.setPosition(newPosition);
}
void Item::setIconPosition(sf::Vector2f newPosition) {
    iconSprite.setPosition(newPosition);
}

void Item::updateItem(float deltaTime, bool forward) {

}
