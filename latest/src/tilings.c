#include <stdio.h>
#include <stdlib.h>

#include "utils_tile.h"
#include "utils_color.h"

int main(int argc, char* argv[])
{
	int seed = 42;
	if (argc > 1)
		seed = atoi(argv[1]) % 255;
	srand(seed);

	struct deck deck;
	deck.size = 0;

	deck_init(&deck);

	for (unsigned int i = 0, s = 0; s < deck.size; s += deck.cards[i++].n)
	{
		printf("tile %d [%d]\n", i, deck.cards[i].n);
		for (int d = 0; d < MAX_DIRECTION; d++)
			printf("->%s\n",
					color_cstring(tile_edge(deck.cards[i].t, d)));

		puts("\n");
	}


	// Free
	for (unsigned int i = 0, s = 0; s < deck.size; s += deck.cards[i++].n)
		free((struct tile*)deck.cards[i].t);

	struct boards board;
	board_init(&board, deck.cards[0].t); //right now I gave the first tile of the deck,
										 //but il will be a random tile in the futur
	return 0;
}
