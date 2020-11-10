#include <stdlib.h>
#include <stdio.h>

#include "utils_player.h"
#include "utils_color.h"
#include "utils_tile.h"

// Create an empty hand
struct hand empty_hand()
{
    struct hand hand = {{}, 0};

    hand.nb_cards = 0;

    return hand;
}

// Init a player with an empty hand and an id
struct player new_player(int id)
{
    struct player player = {};
    player.hand = empty_hand();
    player.id = id;
    return player;
}

// Init the list of players
struct players init_players(int length)
{
    struct players list_of_players;
    struct player player[MAX_PLAYERS];
    for (int i = 0; i < length; ++i)
        player[i] = new_player(i);
    
    *list_of_players.player = *player;
    list_of_players.length = length;

    return list_of_players;
}

// Get the next player
struct player get_next_player(struct player actual_player, struct players list_of_players)
{
    int actual_id = actual_player.id;
    int n = list_of_players.length;
    int next_id = (actual_id + 1 == n) ? 0 : (actual_id + 1);

    while (list_of_players.player[next_id].hand.nb_cards == 0)
            next_id = (next_id + 1 == n) ? 0 : (next_id + 1);

    struct player next_player = list_of_players.player[next_id];

    return next_player;
}

// Test if a player have win
int have_win(struct player player)
{
    return player.hand.nb_cards == 0;
}

// Get the tile on the top of the deck
struct tile top(struct hand hand)
{
    ///////////////////////////////////////////////////
    // Have to find a way to return an empty tile
    // when the hand is empty
    ///////////////////////////////////////////////////

    struct tile top_tile = hand.tiles[0];
    return top_tile;
}

// Pop the tile on the top of the deck
void pop(struct hand* hand)
{
    for (int i = 1; i < hand->nb_cards; ++i)
        hand->tiles[i-1] = hand->tiles[i];
    
    hand->nb_cards -= 1;
}