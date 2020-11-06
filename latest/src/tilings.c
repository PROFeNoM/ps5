#include <stdio.h>
#include <stdlib.h>

#include "tile.h"
#include "color.h"

// It should be include from an header file.
// Its' goal here is to allow to access reference from struct tile to free allocations
struct tile
{
	int i; // Decimal (unique) representation of the Wang tile
	struct color* edges[4]; // Colors of the Wang tile edges
};

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
		for (int d = 0; d < MAX_DIRECTION; d++)
		{
			const char* edge = color_cstring(tile_edge(deck.cards[i].t, d));
			printf("->%s\n", edge);
			free((char*)edge);
		}
		puts("\n");

		s += deck.cards[i].n;
	}

	// Free
	for (int i = 0, s = 0; s < deck.size; s += deck.cards[i++].n)
	{
		for (int d = 0; d < MAX_DIRECTION; d++)
			free(deck.cards[i].t->edges[d]);
		free((struct tile*)deck.cards[i].t);
	}

	return 0;
}