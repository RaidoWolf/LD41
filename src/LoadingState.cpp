#include "../include/LoadingState.hpp"

LoadingState::LoadingState () {

    m_clearWindow = true;
    m_clearColor = sf::Color(255, 255, 255, 255);

    m_progressBar.setWidth(500.0);
    m_progressBar.setHeight(40.0);
    m_progressBar.setPadding(5.0);
    m_progressBar.setOriginToCenter();
    m_progressBar.setPositionX(400.0);
    m_progressBar.setPositionY(300.0);
    m_progressBar.setBackgroundColor(sf::Color(0, 0, 0, 255));
    m_progressBar.setForegroundColor(sf::Color(255, 255, 255, 255));

    auto loadingFont = aw::AssetStore::makeFont("light");
    if (!loadingFont->loadFromFile("./res/fonts/poiretone/PoiretOne-Regular.ttf")) {
        aw::Log::warning("loadingstate", "Could not load ./res/fonts/poiretone/PoiretOne-Regular.ttf.");
    }

    m_loadingText = sf::Text("Loading...", *loadingFont);
    m_loadingText.setCharacterSize(36);
    m_loadingText.setStyle(sf::Text::Regular);
    m_loadingText.setFillColor(sf::Color(0, 0, 0, 255));
    sf::FloatRect loadingTextRect = m_loadingText.getLocalBounds();
    m_loadingText.setOrigin(
        loadingTextRect.left + loadingTextRect.width * 0.5,
        loadingTextRect.top + loadingTextRect.height * 0.5
    );
    m_loadingText.setPosition(
        sf::Vector2f(
            400.0,
            240.0
        )
    );

}

void LoadingState::onActivate () {

    aw::Log::verbose("loadingstate", "Loading...");

    auto mainFont = aw::AssetStore::makeFont("main");
    if (!mainFont->loadFromFile("./res/fonts/press-start-2p/PressStart2P-Regular.ttf")) {
        aw::Log::warning("loadingstate", "Could not load ./res/fonts/press-start-2p/PressStart2P-Regular.ttf");
    }

    auto titleFont = aw::AssetStore::makeFont("title");
    if (!titleFont->loadFromFile("./res/fonts/patua-one/PatuaOne-Regular.ttf")) {
        aw::Log::warning("loadingstate", "Could not load ./res/fonts/patua-one/PatuaOne-Regular.ttf");
    }

    auto titleImage = aw::AssetStore::makeImage("title");
    if (!titleImage->loadFromFile("./res/images/titles/title.png")) {
        aw::Log::warning("loadingstate", "Could not load ./res/images/title.png.");
    }

    //m_progressBar.setFill(0.0);

}

void LoadingState::onDeactivate () {

    aw::Log::verbose("loadingstate", "Loading complete!");

}

void LoadingState::onPush () {

    aw::Log::verbose("loadingstate", "Loading state pushed.");

}

void LoadingState::onPop () {}

void LoadingState::onAscend () {}

void LoadingState::onDescend () {}

void LoadingState::render (double deltaTime) {

    m_progressBar.render();
    aw::Window::draw(m_loadingText);

    // do this in the render loop to prevent accessing graphics code from the wrong thread
    if (m_progressBar.getFill() == 1.0) {
        aw::GameStateManager::pushState("menu");
    }

}

void LoadingState::update () {

    m_progressBar.incrementFill(0.005);

}
