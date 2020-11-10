#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../src/utils_player.h"
#include "../src/utils_tile.h"
#include "../src/utils_color.h"

void display_result(int passed, int tested, char* func_name)
{
	printf("--== %s ==--\n",
			func_name);
	printf("\e[0;32mPASSED\e[0m: %d/%d\n",
			passed, tested);
	printf("\e[0;31mFAILED\e[0m: %d/%d\n",
			tested - passed, tested);
}

/////////////////////////////////////////////
// Change the test for an empty hand
// Define an empty tile with a specific index ?
// Function to detect if hand.tiles is empty ?
/////////////////////////////////////////////
void test_top()
{
    int passed = 0;
    int tested = 0;

    // [1] - Test for empty hand
    tested++;
    struct hand hand_1 = empty_hand();
    struct tile top_tile_1 = top(hand_1);
//    printf("[1] : %d\n", tile_is_empty(&top_tile_1));
    passed += tile_is_empty(&top_tile_1);
    
    // [2] - Test with a hand of black tile
    tested++;
    const struct tile t2 = { 0, {
			&colors_struct[BLACK],
			&colors_struct[BLACK],
			&colors_struct[BLACK],
			&colors_struct[BLACK]
	}};
    struct hand hand_2 = {{t2}, MAX_DECK_SIZE};
    const struct tile top_tile_2 = top(hand_2);
//    printf("[2] : %d\n", tile_equals(&t2, &top_tile_2));
    passed += tile_equals(&t2, &top_tile_2);

    // [3] - Test with an arbitrary hand
    tested++;
    const struct tile t3 = { 7702, {
			&colors_struct[BLACK],
			&colors_struct[GOLDEN],
			&colors_struct[MAGENTA],
			&colors_struct[GREEN]
	}};
    struct hand hand_3 = {{t3,t2}, MAX_DECK_SIZE};
    const struct tile top_tile_3 = top(hand_3);
//    printf("[3] : %d\n", tile_equals(&t3, &top_tile_3));    
    passed += tile_equals(&t3, &top_tile_3);
   
    display_result(passed, tested, "struct tile top(struct hand)");
}

void test_pop()
{
    int passed = 0;
    int tested = 0;

    // [1] - Test with an empty hand
    tested++;


    // [2] - Test with a hand of black tiles
    tested++;
    const struct tile t2 = { 0, {
			&colors_struct[BLACK],
			&colors_struct[BLACK],
			&colors_struct[BLACK],
			&colors_struct[BLACK]
	}};
    struct hand hand_2 = {{t2}, MAX_DECK_SIZE};
    pop(&hand_2);
    const struct tile top_tile_2 = top(hand_2);
//    printf("[2] : %d\n", tile_equals(&t2, &top_tile_2) && hand_2.nb_cards == MAX_DECK_SIZE - 1);
    passed += tile_equals(&t2, &top_tile_2) && (hand_2.nb_cards == MAX_DECK_SIZE - 1);

    // [3] - Test with an arbtrary hand
    tested++;
    const struct tile t3 = { 7702, {
	    	&colors_struct[BLACK],
		    &colors_struct[GOLDEN],
		    &colors_struct[MAGENTA],
	    	&colors_struct[GREEN]
	}};
    struct hand hand_3 = {{t3, t2, t3, t2}, MAX_DECK_SIZE};
    pop(&hand_3);
    const struct tile top_tile_3 = top(hand_3);
//    printf("[2] : %d\n", tile_equals(&t2, &top_tile_3) && hand_3.nb_cards == MAX_DECK_SIZE - 1);
    int test_3 = tile_equals(&t2, &top_tile_3) && hand_3.nb_cards == MAX_DECK_SIZE - 1;
    pop(&hand_3);
    const struct tile top_tile_33 = top(hand_3);
//    printf("[2] : %d\n", tile_equals(&t3, &top_tile_33) && hand_3.nb_cards == MAX_DECK_SIZE - 2);
    test_3 = test_3 && tile_equals(&t3, &top_tile_33) && hand_3.nb_cards == MAX_DECK_SIZE - 2;
    passed += test_3;

    // [4] - Pop until the hand is empty
    tested++;
    const struct tile t4 = { 42, {
            &colors_struct[YELLOW],
            &colors_struct[NAVY],
            &colors_struct[KAKHI],
            &colors_struct[ORANGE]
    }};
    struct hand hand_4 = {{t4, t3, t2, t3, t2, t4, t3}, 7};
    struct tile tiles_4[7] = {t4, t3, t2, t3, t2, t4, t3};
    struct tile top_tile_4 = top(hand_4);
    int nb_cards = 7;
    int i = 0;
    int test_4 = 1;
    while (hand_4.nb_cards > 0 && test_4)
    {
        top_tile_4 = top(hand_4);
//        printf("[%d] %d - %d\n", i, tiles_4[i].i, top_tile_4.i);
  
        test_4 = test_4 && tile_equals(&tiles_4[i], &top_tile_4) && hand_4.nb_cards == nb_cards;
        
        pop(&hand_4);
        nb_cards -= 1;
        i += 1;
    }

    passed += test_4;

    display_result(passed, tested, "void pop(struct hand)");
}

void test_get_next_player()
{
    int passed = 0;
    int tested = 0;

    const struct tile tile = { 0, {
			&colors_struct[BLACK],
			&colors_struct[BLACK],
			&colors_struct[BLACK],
			&colors_struct[BLACK]
	}};
    
    // [1] - Test when the next player has not finished
    struct players list_of_players_1 = { 
        {
            {{{tile}, 1}, 0},
            {{{tile}, 1}, 1},
            {{{tile}, 1}, 2}
        },  
        3 
    };
    
    // [1.1] - Test getting next player for a random actual player
    //         but not the last to play
    tested++;
    struct player actual_player_11 = list_of_players_1.player[0];
    struct player next_player_11 = get_next_player(actual_player_11, list_of_players_1);
    int id_expected_11 = 1;
    passed += (id_expected_11 == next_player_11.id);

    // [1.2] - Test getting next player and actual player is the last 
    //         to play
    tested++;
    struct player actual_player_12 = list_of_players_1.player[2];
    struct player next_player_12 = get_next_player(actual_player_12, list_of_players_1);
    int id_expected_12 = 0;
    passed += (id_expected_12 == next_player_12.id);

    // [2] - Test when the next player has finished
    struct players list_of_players_2 = {
        {
            {{{tile}, 0}, 0},
            {{{tile}, 1}, 1},
            {{{tile}, 0}, 2},
            {{{tile}, 1}, 3}
        },
        4
    };

    // [2.1] - Test getting next player for a random actual player
    //         but not the last to play
    tested++;
    struct player actual_player_21 = list_of_players_2.player[1];
    struct player next_player_21 = get_next_player(actual_player_21, list_of_players_2);
    int id_expected_21 = 3; 
    passed += (id_expected_21 == next_player_21.id);

    // [2.2] - Test getting next player and actual player is the last
    //         to play
    tested++;
    struct player actual_player_22 = list_of_players_2.player[3];
    struct player next_player_22 = get_next_player(actual_player_22, list_of_players_2);
    int id_expected_22 = 1;
    passed += (id_expected_22 == next_player_22.id);

    // [3] - Simulation of one turn of the game
    tested++;
    int test_3 = 1;
    struct players list_of_players_3 = {
        {
            {{{tile}, 1}, 0},
            {{{tile}, 0}, 1},
            {{{tile}, 1}, 2},
            {{{tile}, 1}, 3},
            {{{tile}, 1}, 4},
            {{{tile}, 0}, 5},
            {{{tile}, 1}, 6},
            {{{tile}, 0}, 7}
        },
        8
    };
    struct player actual_player_3 = list_of_players_3.player[3];
    int expected_ids[5] = {4, 6, 0, 2, 3};
    for (int i = 0; i < 5; ++i) {
        actual_player_3 = get_next_player(actual_player_3, list_of_players_3);
        test_3 = test_3 && (expected_ids[i] == actual_player_3.id);
    }
    passed += test_3;

    display_result(passed, tested, "struct player get_next_player(struct player, struct players)");
}

void test_have_win()
{
    int passed = 0;
    int tested = 0;

    const struct tile tile = { 0, {
			&colors_struct[BLACK],
			&colors_struct[BLACK],
			&colors_struct[BLACK],
			&colors_struct[BLACK]
	}};

    // [1] - Test with a player with an empty hand
    tested++;
    struct player player_1 = { {{tile}, 0}, 0 };
    passed += have_win(player_1);

    // [2] - Test with a player with an not empty hand
    tested++;
    struct player player_2 = { {{tile}, 1}, 0 };
    passed += !have_win(player_2);

    // [3] - Simulation of a player who is playing
    tested++;
    struct player player_3 = { {{tile}, 2}, 0 };
    while (!have_win(player_3)) {
        pop(&player_3.hand);
    }
    passed += have_win(player_3);

    display_result(passed, tested, "int have_win(struct player)");
}

int main(int argc, char *argv[])
{
    test_top();
    test_pop();

    test_get_next_player();

    test_have_win();

    return 0;
}
