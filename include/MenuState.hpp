#ifndef H_LD41_MENUSTATE
#define H_LD41_MENUSTATE

#include <functional>
#include <ArcticWolf/GameState.hpp>
#include <ArcticWolf/GameStateManager.hpp>
#include <ArcticWolf/LoopKeybinding.hpp>
#include <ArcticWolf/AssetStore.hpp>
#include <ArcticWolf/Button.hpp>
#include <ArcticWolf/Log.hpp>

class MenuState : public aw::GameState {

public:

    static const bool transparentRender = false;
    static const bool transparentUpdate = false;
    static const bool transparentInput = false;

    MenuState ();
    ~MenuState () = default;

    MenuState (MenuState&&) = default;
    MenuState& operator = (MenuState&&) = default;

    MenuState (const MenuState&) = default;
    MenuState& operator = (const MenuState&) = default;

    void onActivate () override;
    void onDeactivate () override;
    void onPush () override;
    void onPop () override;
    void onAscend () override;
    void onDescend () override;

    void render (double) override;
    void update () override;

    void startGame ();

private:

    std::function<void()> m_startButtonCallback {
        [this] () {
            this->startGame();
        }
    };
    aw::Button m_startButton {
        m_startButtonCallback,
        &m_controller,
        "main",
        "Start",
        50.0,
        12.0,
        sf::Color(0, 0, 0, 255),
        sf::Color(208, 200, 7, 255),
        aw::Button::Alignment::Center
    };

    sf::Text m_subtitle;

    sf::Texture m_titleTexture;
    sf::Sprite m_titleSprite;

};

#endif
