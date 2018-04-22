#include "../include/PlayingState.hpp"

PlayingState::PlayingState () {

    m_clearWindow = true;
    m_clearColor = sf::Color(0, 0, 0, 255);

    m_controller.addLoopKeybinding(aw::LoopKeybinding(
        [&](){
            // TODO: add player moving controls
        },
        sf::Keyboard::Key::W
    ));

    m_controller.addLoopKeybinding(aw::LoopKeybinding(
        [&](){
            // TODO: add player moving controls
        },
        sf::Keyboard::Key::A
    ));

    m_controller.addLoopKeybinding(aw::LoopKeybinding(
        [&](){
            // TODO: add player moving controls
        },
        sf::Keyboard::Key::S
    ));

    m_controller.addLoopKeybinding(aw::LoopKeybinding(
        [&](){
            // TODO: add player moving controls
        },
        sf::Keyboard::Key::D
    ));

}

void PlayingState::onActivate () {

    aw::Log::verbose("playingstate", "Playing...");

}

void PlayingState::onDeactivate () {}

void PlayingState::onPush () {}

void PlayingState::onPop () {}

void PlayingState::onAscend () {}

void PlayingState::onDescend () {}

void PlayingState::render (double deltaTime) {}

void PlayingState::update () {}
