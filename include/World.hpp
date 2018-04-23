#ifndef H_LD41_WORLD
#define H_LD41_WORLD

#include <ctime>
#include <array>
#include <memory>
#include <SFML/Graphics.hpp>
#include <ArcticWolf/FastNoise.h>
#include <ArcticWolf/Window.hpp>
#include <ArcticWolf/Log.hpp>
#include <ArcticWolf/AssetStore.hpp>
#include "Player.hpp"
#include "Enemy.hpp"

class World {

public:

    static constexpr unsigned int width = 64;
    static constexpr unsigned int height = 64;

    enum class TileType {
        Grass,
        Gravel,
        Water,
        Mud,
        Bush,
        Tree,
        Mountain,
        Player,
        Enemy,
        Target
    };

    World ();
    ~World () = default;

    World (World&&) = default;
    World& operator = (World&&) = default;

    World (const World&) = delete;
    World& operator = (const World&) = delete;

    Player* getPlayer ();

    void generateTerrain ();

    void setCamera (double x, double y);
    void moveCamera (double x, double y);
    void render ();

private:

    static constexpr unsigned int indexOf (unsigned int, unsigned int);

    std::unique_ptr<std::array<TileType, width*height>> m_tiles;

    std::unique_ptr<Player> m_player;

    sf::Texture m_grassTexture;
    sf::Sprite m_grassPrinter;
    sf::Texture m_gravelTexture;
    sf::Sprite m_gravelPrinter;
    sf::Texture m_waterTexture;
    sf::Sprite m_waterPrinter;
    sf::Texture m_mudTexture;
    sf::Sprite m_mudPrinter;
    sf::Texture m_bushTexture;
    sf::Sprite m_bushPrinter;
    sf::Texture m_treeTexture;
    sf::Sprite m_treePrinter;
    sf::Texture m_mountainTexture;
    sf::Sprite m_mountainPrinter;

    double m_cameraX {16 * 2 * 32};
    double m_cameraY {16 * 2 * 32};

};

#endif
