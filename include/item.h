#ifndef ITEM_H
#define ITEM_H

#include <SFML/Graphics.hpp>
#include <string> 
#include "GlobalFiles.h"

class Item {
public:
    sf::Vector2i frameSize;
    std::string itemType;
    float itemRotation;
    sf::Texture itemTexture;
    sf::Sprite itemSprite;
    float itemScale = 2;
    sf::Texture itemIconTexture;
    sf::Sprite iconSprite;



    Item();
    Item(std::string type, std::string itemTextureFile,std::string itemIconFile);

    sf::Sprite getItemSprite();
    Item* clone() const;
    void setItemSpriteScale(float xScale, float yScale);
    void setIconSpriteScale(float xScale, float yScale);
    void setItemType(const std::string& newItemType);
    std::string getItemType();
    void updateItem(float deltaTime, bool forward);
    void drawItem(int frame,int state,sf::RenderTarget& target);
    void drawIcon(sf::RenderWindow& myWindow);
    void setItemTexture(sf::Texture newTexture);
    sf::Vector2f getItemPosition();
    void setItemPosition(sf::Vector2f newPosition);
    void setIconPosition(sf::Vector2f newPosition);
};

#endif 
