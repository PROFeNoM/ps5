#ifndef _PLAYER_H_
#define _PLAYER_H_

struct hand; // Anonymous struct for the hand of a player

struct player; // Anonymous struct for a player

struct players; // Anonymous struct for the liste of players

// Create an empty hand
struct hand empty_hand();
// Init a player with an empty hand and an id
struct player new_plaer(int);
// Init the list of players of a length given
struct players init_players(int);
// Get the next player
struct player get_next_player(struct player, struct players);
// Test if a player have win
int have_win(struct player);
// Get the tile on the top of the deck
struct tile top(struct hand);
// Pop the tile on the top of the deck
void pop(struct hand*);

#endif // _PLAYER_H_