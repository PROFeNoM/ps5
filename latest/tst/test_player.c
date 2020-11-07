#include <stdlib.h>
#include <stdio.h>

#include "../src/player.h"
#include "../src/tile.h"
#include "../src/color.h"
#include "../src/utils_color.h"

///// !!! TEMPORARY !!! /////////////////
#define MAX_PLAYERS 20

struct hand
{
    struct tile* tiles[MAX_DECK_SIZE];
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
//////////////////////////////////////////


void test_top()
{
    int success = 0;

    // Test for empty hand
    struct hand empt_hand = empty_hand();
    success += (top(empt_hand) == empty_tile());
    
    // Test for a not empty hand
    struct hand hand;
    struct tile* tile = {0, {0, "black"}};
    struct tile* tiles[MAX_DECK_SIZE] = {tile};
    *hand.tiles = *tiles;
    success += (top(hand) == tile);

    printf("\nstruct tile* top(struct hand* hand):\n");
    printf("\e[92mSUCCESS:\e[0m %d/2\n", success);
    printf("\e[91mFAIL:\e[0m %d/2\n", 1-success);
}

void test_pop()
{

}

int main(int argc, char const *argv[])
{
    printf("# Test: %s\n", argv[0]);

    test_top();
//    test_pop();

    return 0;
}
