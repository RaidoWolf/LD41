#include "../include/World.hpp"

World::World () {

    m_grassTexture.loadFromImage(*aw::AssetStore::getImage("grass"));
    m_gravelTexture.loadFromImage(*aw::AssetStore::getImage("gravel"));
    m_waterTexture.loadFromImage(*aw::AssetStore::getImage("water"));
    m_mudTexture.loadFromImage(*aw::AssetStore::getImage("mud"));
    m_bushTexture.loadFromImage(*aw::AssetStore::getImage("bush"));
    m_treeTexture.loadFromImage(*aw::AssetStore::getImage("tree"));
    m_mountainTexture.loadFromImage(*aw::AssetStore::getImage("mountain"));

    m_grassPrinter = sf::Sprite(m_grassTexture);
    m_gravelPrinter = sf::Sprite(m_gravelTexture);
    m_waterPrinter = sf::Sprite(m_waterTexture);
    m_mudPrinter = sf::Sprite(m_mudTexture);
    m_bushPrinter = sf::Sprite(m_bushTexture);
    m_treePrinter = sf::Sprite(m_treeTexture);
    m_mountainPrinter = sf::Sprite(m_mountainTexture);

    m_player = std::make_unique<Player>(this);

    generateTerrain();

}

Player* World::getPlayer () {

    return m_player.get();

}

void setCamera (double x, double y) {

    m_cameraX = x;
    m_cameraY = y;

}

void moveCamera (double x, double y) {

    m_cameraX += x;
    m_cameraY += y;

}

void World::render () {

    auto size = Window::getContext()->getSize();

    double centerX = size.x * 0.5;
    double centerY = size.y * 0.5;

    double topLeftCoordinateX = cameraX - centerX;
    double topLeftCoordinateY = cameraY - centerY;

    double bottomRightCoordinateX = cameraX + centerX;
    double bottomRightCoordinateY = cameraY + centerY;

    auto topLeftTileX = static_cast<unsigned int>(topLeftCoordinateX / 32.0);
    auto topLeftTileY = static_cast<unsigned int>(topLeftCoordinateY / 32.0);

    auto bottomRightTileX = static_cast<unsigned int>(bottomRightCoordinateX / 32.0);
    auto bottomRightTileY = static_cast<unsigned int>(bottomRightCoordinateY / 32.0);

    double topLeftTileTopLeftCoordinateX = static_cast<double>(topLeftCoordinateX) * 32.0;
    double topLeftTileTopLeftCoordinateY = static_cast<double>(topLeftCoordinateY) * 32.0;

    for (unsigned int y = topLeftTileY; y < bottomRightTileY; ++y) {
        for (unsigned int x = topLeftTileX; x < bottomRightTileX; ++x) {

            switch (m_tilePlane.get(x, y)) {

                case TileType::Grass:
                    m_grassSprite.setPosition(topLeftTileTopLeftCoordinateX - topLeftCoordinateX + (32 * (x - topLeftTileX)), topLeftTileTopLeftCoordinateY - topLeftCoordinateY + (32 * (y - topLeftTileY)));

                case TileType::Gravel:
                    m_grassSprite.setPosition(topLeftTileTopLeftCoordinateX - topLeftCoordinateX + (32 * (x - topLeftTileX)), topLeftTileTopLeftCoordinateY - topLeftCoordinateY + (32 * (y - topLeftTileY)));

                case TileType::Water:
                    m_grassSprite.setPosition(topLeftTileTopLeftCoordinateX - topLeftCoordinateX + (32 * (x - topLeftTileX)), topLeftTileTopLeftCoordinateY - topLeftCoordinateY + (32 * (y - topLeftTileY)));

                case TileType::Mud:
                    m_grassSprite.setPosition(topLeftTileTopLeftCoordinateX - topLeftCoordinateX + (32 * (x - topLeftTileX)), topLeftTileTopLeftCoordinateY - topLeftCoordinateY + (32 * (y - topLeftTileY)));

                case TileType::Bush:
                    m_grassSprite.setPosition(topLeftTileTopLeftCoordinateX - topLeftCoordinateX + (32 * (x - topLeftTileX)), topLeftTileTopLeftCoordinateY - topLeftCoordinateY + (32 * (y - topLeftTileY)));

                case TileType::Tree:
                    m_grassSprite.setPosition(topLeftTileTopLeftCoordinateX - topLeftCoordinateX + (32 * (x - topLeftTileX)), topLeftTileTopLeftCoordinateY - topLeftCoordinateY + (32 * (y - topLeftTileY)));

                case TileType::Mountain:\
                    m_grassSprite.setPosition(topLeftTileTopLeftCoordinateX - topLeftCoordinateX + (32 * (x - topLeftTileX)), topLeftTileTopLeftCoordinateY - topLeftCoordinateY + (32 * (y - topLeftTileY)));

                case TileType::Player:
                    m_grassSprite.setPosition(topLeftTileTopLeftCoordinateX - topLeftCoordinateX + (32 * (x - topLeftTileX)), topLeftTileTopLeftCoordinateY - topLeftCoordinateY + (32 * (y - topLeftTileY)));

                case TileType::Enemy:
                    m_grassSprite.setPosition(topLeftTileTopLeftCoordinateX - topLeftCoordinateX + (32 * (x - topLeftTileX)), topLeftTileTopLeftCoordinateY - topLeftCoordinateY + (32 * (y - topLeftTileY)));

                case TileType::Target:
                    m_grassSprite.setPosition(topLeftTileTopLeftCoordinateX - topLeftCoordinateX + (32 * (x - topLeftTileX)), topLeftTileTopLeftCoordinateY - topLeftCoordinateY + (32 * (y - topLeftTileY)));

                default:
                    break;

            }

        }
    }

}
