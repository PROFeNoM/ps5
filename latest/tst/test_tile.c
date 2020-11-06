#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "../src/tile.h"
#include "../src/color.h"
#include "../src/ansi.h"

// TODO: Remove these structs (move it) as soon as they're implemented in a header

// Temporary
struct tile
{
	int i; // Decimal (unique) representation of the Wang tile
	struct color* edges[4]; // Colors of the Wang tile edges
};

// Temporary
struct color
{
	int c; // Decimal representation of the color
	char* name; // Name of the color
};

// Temporary
struct color colors_struct[MAX_COLORS] =
		{
				{ 0, "BLACK" },
				{ 1, "RED" },
				{ 2, "GREEN" },
				{ 3, "YELLOW" },
				{ 4, "BLUE" },
				{ 5, "MAGENTA" },
				{ 6, "CYAN" },
				{ 7, "WHITE" },
				{ 8, "NAVY" },
				{ 9, "DARK_GREEN" },
				{ 10, "DARK_RED" },
				{ 11, "PURPLE" },
				{ 12, "BROWN" },
				{ 13, "KAKHI" },
				{ 14, "PALE_BLUE" },
				{ 15, "PALE_PURPLE" },
				{ 16, "ORANGE" },
				{ 17, "PALE_GREEN" },
				{ 18, "PINK" },
				{ 19, "GOLDEN" }
		};

void display_result(int passed, int tested, char* func_name)
{
	printf("--== %s ==--\n",
			func_name);
	printf("\e[0;32mPASSED\e[0m: %d/%d\n",
			passed, tested);
	printf("\e[0;31mFAILED\e[0m: %d/%d\n",
			tested - passed, tested);
}

void test_tile_is_empty()
{
	int passed = 0,
			tested = 0;

	int expected, actual;

	// [1] : Test with an empty tile
	tested++;
	const struct tile* t1 = NULL;
	expected = 1;
	actual = tile_is_empty(t1);
	if (expected == actual)
		passed++;
	else
	{
		printf("[tile_is_empty][1] - \n\texpected: %d\n\tactual: %d\n",
				expected, actual);
	}

	// TODO: change tile_is_empty so it checks memory address with empty tile's one

	// [2] : Test with an empty tile
	tested++;
	const struct tile t11 = {};
	expected = 1;
	//const struct tile *t12 = &t11;
	//printf("%zd %zd %zd %p %p %p %d, %d\n",
	//		sizeof(t1), sizeof(t11), sizeof(t11.i), &t11, &t1, t12, t12 == &t11, t1 == &t11);
	actual = tile_is_empty(&t11);
	if (expected == actual)
		passed++;
	else
	{
		printf("[tile_is_empty][2] - \n\texpected: %d\n\tactual: %d\n",
				expected, actual);
	}

	// [3] - Test with a full black tile
	tested++;

	const struct tile t2 = { 0, {
			&colors_struct[BLACK],
			&colors_struct[BLACK],
			&colors_struct[BLACK],
			&colors_struct[BLACK]
	}};
	//printf("%d\n", &t2 == &t11);
	expected = 0;
	actual = tile_is_empty(&t2);
	//printf("->%zd %zd\n", sizeof(t2), sizeof(t2.i));
	if (expected == actual)
		passed++;
	else
	{
		printf("[tile_is_empty][3] - \n\texpected: %d\n\tactual: %d\n",
				expected, actual);
	}

	// [4] - Test with an arbitrary tile
	tested++;

	const struct tile t3 = { 7702, {
			&colors_struct[BLACK],
			&colors_struct[GOLDEN],
			&colors_struct[MAGENTA],
			&colors_struct[GREEN]
	}};
	expected = 0;
	actual = tile_is_empty(&t3);
	if (expected == actual)
		passed++;
	else
	{
		printf("[tile_is_empty][4] - \n\texpected: %d\n\tactual: %d\n",
				expected, actual);
	}
	display_result(passed, tested, "tile_is_empty");
}

void test_tile_equals()
{
	int passed = 0,
			tested = 0;

	int expected, actual;

	// TODO: make_tile() to make it easier creating tiles

	// [1] (C: 20)
	tested++;

	const struct tile t5 = { 7702, {
			&colors_struct[BLACK],
			&colors_struct[GOLDEN],
			&colors_struct[MAGENTA],
			&colors_struct[GREEN],
	}};

	const struct tile t6 = { 7702, {
			&colors_struct[BLACK],
			&colors_struct[GOLDEN],
			&colors_struct[MAGENTA],
			&colors_struct[GREEN],
	}};

	expected = 1;
	actual = tile_equals(&t5, &t6);
	if (expected == actual)
		passed++;
	else
	{
		printf("[tile_equals][1] - \n\texpected: %d\n\tactual: %d\n",
				expected, actual);
	}

	// [2] (C: 20)
	tested++;

	const struct tile t7 = { 0, {
			&colors_struct[BLACK],
			&colors_struct[BLACK],
			&colors_struct[BLACK],
			&colors_struct[BLACK],
	}};

	expected = 0;
	actual = tile_equals(&t5, &t7);
	if (expected == actual)
		passed++;
	else
	{
		printf("[tile_equals][2] - \n\texpected: %d\n\tactual: %d\n",
				expected, actual);
	}

	// [3] (C:20)
	tested++;

	expected = 0;
	actual = tile_equals(&t6, &t7);
	if (expected == actual)
		passed++;
	else
	{
		printf("[tile_equals][3] - \n\texpected: %d\n\tactual: %d\n",
				expected, actual);
	}

	// [4] (C: 20) Tiles with same colors, not on the same edges
	tested++;

	const struct tile t8 = { 152102, {
			&colors_struct[GOLDEN],
			&colors_struct[BLACK],
			&colors_struct[MAGENTA],
			&colors_struct[GREEN],
	}};

	expected = 0;
	actual = tile_equals(&t6, &t8);
	if (expected == actual)
		passed++;
	else
	{
		printf("[tile_equals][3] - \n\texpected: %d\n\tactual: %d\n",
				expected, actual);
	}

	display_result(passed, tested, "tile_equals");
}

void test_tile_edge()
{
	int passed = 0,
			tested = 0;
	struct color* expected, * actual;

	// [1] (C: 20)
	tested++;

	const struct tile t1 = { 0, {
			&colors_struct[BLACK],
			&colors_struct[BLACK],
			&colors_struct[BLACK],
			&colors_struct[BLACK],
	}};

	actual = tile_edge(&t1, NORTH);
	expected = &colors_struct[BLACK];
	if (expected == actual)
		passed++;
	else
	{
		printf("[tile_edge][1] - \n\texpected: %s\n\tactual: %s\n",
				expected->name, actual->name);
	}

	// [2] (C: 2)
	tested++;

	const struct tile t2 = { 11, {
			&colors_struct[RED],
			&colors_struct[BLACK],
			&colors_struct[RED],
			&colors_struct[RED],
	}};

	actual = tile_edge(&t2, NORTH);
	expected = &colors_struct[RED];
	if (expected == actual)
		passed++;
	else
	{
		printf("[tile_edge][2] - \n\texpected: %s\n\tactual: %s\n",
				expected->name, actual->name);
	}

	// [3] (C: 2)
	tested++;

	actual = tile_edge(&t2, SOUTH);
	expected = &colors_struct[BLACK];
	if (expected == actual)
		passed++;
	else
	{
		printf("[tile_edge][3] - \n\texpected: %s\n\tactual: %s\n",
				expected->name, actual->name);
	}

	display_result(passed, tested, "tile_edge");

	// [4] (C: 2)
	tested++;

	actual = tile_edge(&t2, EAST);
	expected = &colors_struct[RED];
	if (expected == actual)
		passed++;
	else
	{
		printf("[tile_edge][4] - \n\texpected: %s\n\tactual: %s\n",
				expected->name, actual->name);
	}

	// [5] (C: 2)
	tested++;

	actual = tile_edge(&t2, WEST);
	expected = &colors_struct[RED];
	if (expected == actual)
		passed++;
	else
	{
		printf("[tile_edge][5] - \n\texpected: %s\n\tactual: %s\n",
				expected->name, actual->name);
	}

	// [6] (C: 4)
	tested++;

	const struct tile t3 = { 108, {
			&colors_struct[RED],
			&colors_struct[GREEN],
			&colors_struct[YELLOW],
			&colors_struct[BLACK],
	}};

	actual = tile_edge(&t3, NORTH);
	expected = &colors_struct[RED];
	if (expected == actual)
		passed++;
	else
	{
		printf("[tile_edge][6] - \n\texpected: %s\n\tactual: %s\n",
				expected->name, actual->name);
	}

	// [7] (C: 4)
	tested++;

	actual = tile_edge(&t3, SOUTH);
	expected = &colors_struct[GREEN];
	if (expected == actual)
		passed++;
	else
	{
		printf("[tile_edge][7] - \n\texpected: %s\n\tactual: %s\n",
				expected->name, actual->name);
	}

	// [8] (C: 4)
	tested++;

	actual = tile_edge(&t3, EAST);
	expected = &colors_struct[YELLOW];
	if (expected == actual)
		passed++;
	else
	{
		printf("[tile_edge][8] - \n\texpected: %s\n\tactual: %s\n",
				expected->name, actual->name);
	}

	// [9] (C: 4)
	tested++;

	actual = tile_edge(&t3, WEST);
	expected = &colors_struct[BLACK];
	if (expected == actual)
		passed++;
	else
	{
		printf("[tile_edge][9] - \n\texpected: %s\n\tactual: %s\n",
				expected->name, actual->name);
	}

	display_result(passed, tested, "tile_edge");
}

void test_deck_init(int seed)
{
	int passed = 0,
			tested = 0;

	struct deck deck;
	deck.size = 0;

	deck_init(&deck);

	// [1] Check if deck is composed of non empty tiles
	// [2] Check if those tiles are valid, i.e.:
	//		- [2.1] Edges color are valid
	//		- [2.2] Duplicates, etc. are handled within deck_pair

	int is_empty = 0,
			is_edge_valid = 1,
			is_handling_duplicate = 1;
	for (int i = 0, s = 0; s < deck.size; s += deck.cards[i++].n)
	{
		// [1]
		if (tile_is_empty(deck.cards[i].t))
		{
			printf("[deck_init][1][seed: %d] tile is empty on index %d\n",
					seed, i);
			is_empty = 1;
		}

		// [2.1]
		for (int direction = NORTH; direction < MAX_DIRECTION; direction++)
			if ((0 > deck.cards[i].t->edges[direction]->c ||
					deck.cards[i].t->edges[direction]->c > MAX_COLORS) ||
					strcmp(deck.cards[i].t->edges[direction]->name,
							colors_names[deck.cards[i].t->edges[direction]->c]) != 0)
			{
				printf("[deck_init][2.1][seed: %d] edge (i=%d, direction=%d) not valid\n",
						seed, i, direction);
				is_edge_valid = 0;
			}

		// [2.2]
		int cnt = 0;
		for (int ii = 0, ss = 0; ss < deck.size; ss += deck.cards[ii++].n)
			cnt += tile_equals(deck.cards[ii].t, deck.cards[i].t);
		if (cnt != deck.cards[i].n)
		{
			printf("[deck_init][2.2][seed: %d] cnt = %d // n = %d\n",
					seed, cnt, deck.cards[i].n);
			is_handling_duplicate = 0;
		}

	}
	passed += is_empty == 0;
	tested++;

	passed += is_edge_valid;
	tested++;

	passed += is_handling_duplicate;
	tested++;

	display_result(passed, tested, "deck_init");
}

int main(int argc, char* argv[])
{
	int seed = time(NULL);
	if (argc > 1)
		seed = atoi(argv[1]);
	srand(seed);

	test_tile_is_empty();

	test_tile_equals();

	test_tile_edge();

	test_deck_init(seed);

	return 0;
}