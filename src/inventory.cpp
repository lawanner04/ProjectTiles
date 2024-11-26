#include "inventory.h"

Inventory::Inventory() {
    tileTextureFile = basePath + "images/hotBarTile.png";
    selectedTileTextureFile = basePath + "images/hotBarTileSelected.png";
    tileTexture.loadFromFile(tileTextureFile);
    selectedTileTexture.loadFromFile(selectedTileTextureFile);
    selectedItemID = 0;
    setUpHotbar();
}

void Inventory::updateInventory(float deltaTime) {
    // Update logic can be implemented here if needed
}

void Inventory::setUpHotbar() {
    float scale = 2.0f;
    int tileWidth = 30 * scale;

    for (int i = 0; i < 7; i++) {
        hotbarTiles.push_back(sf::Sprite(tileTexture));
        hotbarTiles[i].setOrigin(1, 1);
        hotbarTiles[i].setScale(scale, scale);
        // Initial position will be set dynamically based on the player's position.
    }
}


void Inventory::updateSelectedItemID(sf::Event event){
    if (event.type == sf::Event::MouseWheelScrolled) {
        int inventorySize = inventoryItems.size();
        if (event.mouseWheelScroll.delta < 0) {
            prevSelectedItemID = selectedItemID;
            selectedItemID = (selectedItemID == 6) ? 0 : selectedItemID + 1;
        } else if (event.mouseWheelScroll.delta > 0) {
            prevSelectedItemID = selectedItemID;
            selectedItemID = (selectedItemID == 0) ? 6 : selectedItemID - 1;
        }
    }
}

void Inventory::updateHotbar(sf::Vector2f playerPosition) {
    float scale = 1.0f;
    int tileWidth = 30 * scale;
    float hotbarYOffset = 100.0f; // Distance from the player to the hotbar on the Y-axis
    float hotbarXOffset = -3 * tileWidth; // Center the hotbar around the player on the X-axis

    for (int i = 0; i < 7; i++) {
        sf::Vector2f hotbarTilePosition = playerPosition + sf::Vector2f(hotbarXOffset + i * tileWidth, hotbarYOffset);
        hotbarTiles[i].setScale(scale, scale);
        hotbarTiles[i].setTexture(tileTexture);
        hotbarTiles[i].setPosition(hotbarTilePosition);

        if (i < inventoryItems.size() && inventoryItems[i]) {
            inventoryItems[i]->setIconPosition(hotbarTilePosition );
            inventoryItems[i]->setIconSpriteScale(1.5*scale,1.5*scale);
        }
    }

    // Highlight the selected tile
    hotbarTiles[selectedItemID].setTexture(selectedTileTexture);
}


void Inventory::addItem(const Item& newItem) {
    inventoryItems.push_back(std::make_unique<Item>(newItem));
}

void Inventory::displayHotbar(sf::RenderWindow& window) {
    for (int i = 0; i < 7; i++) {
        window.draw(hotbarTiles[i]);
        if (i < inventoryItems.size() && inventoryItems[i]) {
            inventoryItems[i]->setIconPosition(hotbarTiles[i].getPosition()+sf::Vector2f(5,5));
            inventoryItems[i]->drawIcon(window);
        }
    }
    window.draw(hotbarTiles[selectedItemID]);
    if (selectedItemID < inventoryItems.size() && inventoryItems[selectedItemID]) {
        
        inventoryItems[selectedItemID]->drawIcon(window);
    }
}

Item* Inventory::getSelectedItem() {
    return (selectedItemID < inventoryItems.size()) ? inventoryItems[selectedItemID].get() : nullptr;
}
