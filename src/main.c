#include <stdio.h>
#include <stdlib.h>

#include "tile.h"
#include "color.h"

int main(int argc, char* argv[])
{
	int seed = 42;
	if (argc > 1)
		seed = atoi(argv[1]) % 255;
	srand(seed);

	struct deck deck;
	deck.size = 0;

	deck_init(&deck);

	for (int i = 0, s = 0; s < deck.size; i++)
	{
		printf("tile %d [%d]\n", i, deck.cards[i].n);
		printf("->%s\n", color_cstring(tile_edge(deck.cards[i].t, NORTH)));
		printf("->%s\n", color_cstring(tile_edge(deck.cards[i].t, SOUTH)));
		printf("->%s\n", color_cstring(tile_edge(deck.cards[i].t, EAST)));
		printf("->%s\n", color_cstring(tile_edge(deck.cards[i].t, WEST)));
		puts("\n");

		s += deck.cards[i].n;
	}

	return 0;
}