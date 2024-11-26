#ifndef INVENTORY_H
#define INVENTORY_H

#include <SFML/Graphics.hpp>
#include "GlobalFiles.h"
#include <string>
#include <vector>
#include <memory>
#include "item.h"

class Inventory {
public:
    int selectedItemID;
    int prevSelectedItemID;
    std::string tileTextureFile;
    std::string selectedTileTextureFile;
    sf::Texture tileTexture;
    sf::Texture selectedTileTexture;
    std::vector<sf::Sprite> hotbarTiles;
    int inventorySize = 7;

    Inventory();
    ~Inventory() = default;

    std::vector<std::unique_ptr<Item>> inventoryItems;

    void updateSelectedItemID(sf::Event event);
    void addItem(const Item& newItem);
    void setUpInventory();
    void displayInventory(sf::RenderWindow& window);
    void updateInventory(float deltaTime);
    void setUpHotbar();
    void displayHotbar(sf::RenderWindow& window);
    void updateHotbar(sf::Vector2f playerPosition);
    Item* getSelectedItem();
};

#endif
