#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>  // Include cmath for sqrt()
#include <ctime>   // for time()
#include "player.h"
#include "item.h"
#include "collisionManager.h"
#include "worldMap.h"
#include "GlobalFiles.h"
#include "enemy.h"

int main() {
    srand(time(0));
    WorldMap worldMap1(basePath+"/tilemaps/snowy_plain.tmx",basePath+"/images/seasonal sample (winter).png");
    CollisionManager collisionManager;
    if (worldMap1.loadMap()) {
        auto collisionBounds = worldMap1.getCollisionBounds();
        collisionManager.addCollisionBounds(collisionBounds);
    }
    Player player("./images/knight.png");
    Enemy darkKnight("./images/darkKnight.png");
    Item shortSword("sword",basePath+"/images/shortSword.png",basePath+"/images/sword.png");
    player.addItem(shortSword);
    darkKnight.addItem(shortSword);
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "projectTiles");
    sf::View followView(sf::FloatRect(0, 0, 500, 300));  
    sf::Clock clk;

    bool start = false;

    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile(basePath+"/images/startScreen.png");
    sf::Sprite  background(backgroundTexture);
    background.setScale(1,1);
    background.setPosition(0, 0);

    while (window.isOpen()) {
        if(!start){
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
               start = true;
            }
            window.clear();
            window.draw(background);

        }
        if(start){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                start = false;
            }
            sf::Event event;
            float deltaTimeMain = clk.restart().asSeconds();

            player.updatePlayer(deltaTimeMain,collisionManager);
            darkKnight.update(deltaTimeMain,collisionManager);
            darkKnight.moveEnemy(player,deltaTimeMain,collisionManager);

            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                player.updatePlayerSelectedItem(event);
                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    player.playerAttack();
                }
            }

            followView.setCenter(player.getPlayerPosition().x, player.getPlayerPosition().y); 
            window.clear();
            window.setView(followView);
            worldMap1.drawLayer(window,0);
            player.drawPlayer(window);  
            darkKnight.draw(window);
            worldMap1.drawLayer(window,1); 
            sf::FloatRect hotbarRect(0.f, 0.f, 1920.f, 200.f); window.setView(followView);
            player.drawPlayerHotbar(window);  


            
        }
        window.display();
    }

    return 0;
}
