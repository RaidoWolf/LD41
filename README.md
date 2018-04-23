# LD41

Step-by-Step Deathmatch - My project for Ludum Dare 41!

## Theme

Combine Two Incompatible Genres

## License

MIT (see LICENSE)

## Description

Step-by-Step Deathmatch is a turn-based battle royale shooter game. The world
is represented by a grid, and you can only move from tile to tile, as can your
enemies. You will be dropped randomly into a randomly generated world populated
with many enemies who want only to kill you (and each other, but mostly you).

You will need to eliminate all enemy players, and to do that, you will have to
take your turns. Each round, you will receive a number of "turns" which will
allow you to perform exactly one action, be it to move one tile, shoot one shot,
or pick up an item. Each round, one player or AI moves at a time, and in a
random order.

There is no real "score" because you are just trying to be the last man
standing. This "remaining players" stat is available however, and that's how
you can track your performance.

There will be certain blocks that might slow you down, others that might block
you (and bullets) entirely.

The only way to win is to be the last one left. By any means necessary.

## Development

### Day 0 (Friday - April 20, 2018)

I spent the first 15 or so minutes being salty about the theme choice, and
hoping that somebody would create an unofficial alternative theme like they did
last time. After that, I spent a few hours working on a very large and complex
matrix of theme combinations, which can be found here:
https://docs.google.com/spreadsheets/d/1enpKy0W-tg2E0qfAFEgJiEbspktFyc9wtLarmGe-WpQ/edit?usp=sharing

After that, I started working on porting over some changes from my TimberWolf
game engine to ArcticWolf so I'd have some useful framework/engine features
ready once I came up with my theme combo.

### Day 1 (Saturday - April 21, 2018)

I got up fairly early in the morning to get a good long day in. Probably not an
early morning in the minds of you "morning people" though. I spent countless
hours adding features to ArcticWolf in preparation for this game jam, and I
largely ignored the theme and didn't try to think about any game idea.

Hours and hours later, there are still some missing features in the engine, but
major progress had been made and although I was feeling completely exhausted, I
felt like I was going to be able to finish on time still, albeit slightly
further behind schedule than I would have liked.

After deciding to turn in for the night, I started thinking about some ideas
that might be fun and I came up with one that I think is pretty good. Initially
I considered "turn-based" and "roguelike," and I was going to make a game
similar to a simplified Binding of Isaac, but I realized that the complexity of
it was still probably beyond what I was prepared for, so I dialed it back to
a single room, and changed it to "turn-based" and "shooter." I then realized
that I could make a fairly large room with lots of AI enemies, and that, despite
not being multiplayer, is essentially a "battle-royale."

So officially I decided it would be "turn-based battle royale" and the game
would be called "Turn-by-Turn Deathmatch."

### Day 2 (Sunday - April 22, 2018)

IN PROGRESS

I woke up a little bit later, getting started right around noon. I worked on a
few more minor changes to the ArcticWolf engine, but mainly I wanted today to be
focused on getting a workable item, as tomorrow I will need to have something to
play.

My initial plan was to port the changes I had made over to my Ludum Dare 40 game
just to make sure they worked. I also decided to fix a longstanding bug with my
Ludum Dare 40 game, which was that it would randomly segfault sometimes. All it
needed was a little attention from GDB to find that the culprit was graphics
code being called from the update loop because of a GameStateManager::push()
call.

With that out of the way, I started copying some code from that project over to
the new repository and creating some basic assets. There is a visible game now,
and that's pretty exciting, even if it doesn't do anything just yet.

Stay tuned.
