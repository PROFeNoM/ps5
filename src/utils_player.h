#ifndef _UTILS_PLAYER_H_
#define _UTILS_PLAYER_H_

#include "player.h"
#include "utils_color.h"
#include "utils_tile.h"

#define MAX_PLAYERS 20

struct hand
{
    struct tile tiles[MAX_DECK_SIZE];
    int nb_cards;
};

struct player
{
    struct hand hand;
    int id;
};

struct players
{
    struct player player[MAX_PLAYERS];
    int length;
};

#endif // _UTILS_PLAYER_H_