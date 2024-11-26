#ifndef WORLDMAP_H
#define WORLDMAP_H

#include <tmxlite/Map.hpp>
#include <tmxlite/Layer.hpp>
#include <tmxlite/TileLayer.hpp>

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "GlobalFiles.h"


class WorldMap{
public:
    WorldMap(const std::string& mapFile, const std::string& tileSetFile);
    ~WorldMap() = default;

    bool loadMap();
    void updateMap(float deltaTime);
    void drawMap(sf::RenderTarget &target) const;
    void drawLayer(sf::RenderTarget& target,  size_t layerIndex) const;

    sf::Vector2u getMapSize() const;
    sf::Vector2u getTileSize() const;
    std::vector<sf::FloatRect> getCollisionBounds() const;   
    void printAllLayers() const;  

private:
    void parseTileLayers();          
    void parseObjectLayers();

   

    void buildLayer(const tmx::TileLayer& layer); 



    tmx::Map worldMap;                   
    sf::Texture worldMapTileSet;            
    sf::Vector2u worldMapSize;          
    sf::Vector2u worldMapTileSize;     

    struct Layer {
        sf::VertexArray vertices;   
        sf::RenderStates renderState; 
    };

    std::vector<Layer> worldMapLayers;      

};


#endif