#include "../include/MenuState.hpp"

MenuState::MenuState () {

    m_clearWindow = true;
    m_clearColor = sf::Color(208, 200, 7, 255);

    m_startButton.setPosition(400, 300);

}

void MenuState::onActivate () {

    aw::Log::verbose("menustate", "Launching Menu.");

    m_startButton.setFont("main");

    m_subtitle = sf::Text("Ludum Dare 41 Project by Alexander Barber", *aw::AssetStore::getFont("main"));
    m_subtitle.setCharacterSize(16);
    m_subtitle.setStyle(sf::Text::Regular);
    m_subtitle.setFillColor(sf::Color(0, 0, 0, 255));
    sf::FloatRect subtitleRect = m_subtitle.getLocalBounds();
    m_subtitle.setOrigin(
        subtitleRect.left + subtitleRect.width * 0.5,
        subtitleRect.top + subtitleRect.height * 0.5
    );
    m_subtitle.setPosition(
        sf::Vector2f(
            400.0,
            240.0
        )
    );

    m_titleTexture.loadFromImage(*aw::AssetStore::getImage("title"));
    m_titleSprite = sf::Sprite(m_titleTexture);
    m_titleSprite.setOrigin(144.0, 16.0);
    m_titleSprite.setScale(2.0, 2.0);
    m_titleSprite.setPosition(400.0, 180.0);

}

void MenuState::onDeactivate () {}

void MenuState::onPush () {}

void MenuState::onPop () {}

void MenuState::onAscend () {}

void MenuState::onDescend () {}

void MenuState::render (double deltaTime) {

    aw::Window::draw(m_titleSprite);
    aw::Window::draw(m_subtitle);
    m_startButton.render();

}

void MenuState::update () {}

void MenuState::startGame () {

    aw::GameStateManager::pushState("playing");

}
