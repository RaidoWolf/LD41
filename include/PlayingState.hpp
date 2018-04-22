#ifndef H_LD41_PLAYINGSTATE
#define H_LD41_PLAYINGSTATE

#include <ArcticWolf/GameState.hpp>
#include <ArcticWolf/Log.hpp>

class PlayingState : public aw::GameState {

public:

    static const bool transparentRender = false;
    static const bool transparentUpdate = false;
    static const bool transparentInput = false;

    PlayingState ();
    ~PlayingState () = default;

    PlayingState (PlayingState&&) = default;
    PlayingState& operator = (PlayingState&&) = default;

    PlayingState (const PlayingState&) = default;
    PlayingState& operator = (const PlayingState&) = default;

    void onActivate () override;
    void onDeactivate () override;
    void onPush () override;
    void onPop () override;
    void onAscend () override;
    void onDescend () override;

    void render (double) override;
    void update () override;

private:

};

#endif
