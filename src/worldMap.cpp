#include "worldMap.h"

WorldMap::WorldMap(const std::string& mapFile, const std::string& tileSetFile)
: worldMap(), worldMapTileSet(), worldMapSize(0, 0), worldMapTileSize(0, 0) {
    if (!worldMap.load(mapFile)) {
        throw std::runtime_error("Failed to load TMX map!");
    }

    if (!worldMapTileSet.loadFromFile(tileSetFile)) {
        throw std::runtime_error("Failed to load tileset texture!");
    }
}

bool WorldMap::loadMap() {
    worldMapSize = sf::Vector2u(worldMap.getTileCount().x, worldMap.getTileCount().y);
    worldMapTileSize = sf::Vector2u(worldMap.getTileSize().x, worldMap.getTileSize().y);

    parseTileLayers();
    parseObjectLayers();
    return true;
}

void WorldMap::updateMap(float deltaTime) {
    // Update logic here (if needed)
}

void WorldMap::parseTileLayers() {
    for (const auto& layer : worldMap.getLayers()) {
        if (layer->getType() == tmx::Layer::Type::Tile) {
            const auto& tileLayer = layer->getLayerAs<tmx::TileLayer>();
            buildLayer(tileLayer);
        }
    }
}

void WorldMap::buildLayer(const tmx::TileLayer& layer) {
    int scale = 1;
    Layer mapLayer;
    mapLayer.vertices.setPrimitiveType(sf::Quads);
    int x;
    int y;
    const auto& tiles = layer.getTiles();

    // Use the already loaded tileset (no need to reload here)
    const auto& tileset = worldMap.getTilesets()[0]; 

    for (unsigned yp = 0; yp < worldMapSize.y; ++yp) {
        for (unsigned xp = 0; xp < worldMapSize.x; ++xp) {
            x = scale * xp;
            y = scale * yp;
            std::size_t index = xp + yp * worldMapSize.x;
            unsigned int tileID = tiles[index].ID;

            if (tileID == 0) continue; // Skip empty tiles

            bool isImPassable = false;

            // Calculate texture coordinates
            unsigned int tu = (tileID - 1) % (worldMapTileSet.getSize().x / worldMapTileSize.x);
            unsigned int tv = (tileID - 1) / (worldMapTileSet.getSize().x / worldMapTileSize.x);

            // Define quad
            sf::Vertex quad[4];
            quad[0].position = sf::Vector2f(x * worldMapTileSize.x, y * worldMapTileSize.y);
            quad[1].position = sf::Vector2f((x + 1) * worldMapTileSize.x, y * worldMapTileSize.y);
            quad[2].position = sf::Vector2f((x + 1) * worldMapTileSize.x, (y + 1) * worldMapTileSize.y);
            quad[3].position = sf::Vector2f(x * worldMapTileSize.x, (y + 1) * worldMapTileSize.y);

            quad[0].texCoords = sf::Vector2f(tu * worldMapTileSize.x, tv * worldMapTileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * worldMapTileSize.x, tv * worldMapTileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * worldMapTileSize.x, (tv + 1) * worldMapTileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * worldMapTileSize.x, (tv + 1) * worldMapTileSize.y);

            for (int i = 0; i < 4; ++i)
                mapLayer.vertices.append(quad[i]);
        }
    }

    mapLayer.renderState.texture = &worldMapTileSet;
    worldMapLayers.push_back(std::move(mapLayer));
}

void WorldMap::drawMap(sf::RenderTarget& target) const {
    for (const auto& layer : worldMapLayers) {
        target.draw(layer.vertices, layer.renderState);
    }
}
void WorldMap::drawLayer(sf::RenderTarget& target, size_t layerIndex) const {
    // Ensure the layer index is valid
    if (layerIndex >= worldMapLayers.size()) {
        return; // Do nothing if index is out of bounds
    }

    // Draw the specified layer
    const auto& layer = worldMapLayers[layerIndex];
    target.draw(layer.vertices, layer.renderState);
}



void WorldMap::parseObjectLayers() {
    for (const auto& layer : worldMap.getLayers()) {
        if (layer->getType() == tmx::Layer::Type::Object) {
            const auto& objectGroup = layer->getLayerAs<tmx::ObjectGroup>();
            for (const auto& object : objectGroup.getObjects()) {

            }
        }
    }
}

void WorldMap::printAllLayers() const {
    std::cout << "World Map Layers:" << std::endl;

    for (size_t i = 0; i < worldMapLayers.size(); ++i) {
        const auto& layer = worldMapLayers[i];
        std::cout << "Layer " << i << ":" << std::endl;
        std::cout << "  Vertex Count: " << layer.vertices.getVertexCount() << std::endl;

        if (layer.renderState.texture) {
            std::cout << "  Texture: Yes" << std::endl;
        } else {
            std::cout << "  Texture: No" << std::endl;
        }
    }
}


std::vector<sf::FloatRect> WorldMap::getCollisionBounds() const {
    std::vector<sf::FloatRect> bounds;
    for (const auto& layer : worldMap.getLayers()) {
        if (layer->getType() == tmx::Layer::Type::Object) {
            const auto& objectGroup = layer->getLayerAs<tmx::ObjectGroup>();
            for (const auto& object : objectGroup.getObjects()) {
                sf::FloatRect rect(object.getAABB().left, object.getAABB().top, object.getAABB().width, object.getAABB().height);
                bounds.push_back(rect);
            }
        }
    }
    return bounds;
}
