#include <time.h>

#include "utils_tile.h"
#include "utils_color.h"
//#include "board.h"

int main(int argc, char* argv[])
{
	int seed = time(NULL);
	if (argc > 1)
		seed = atoi(argv[1]) % 255;
	srand(seed);

	struct deck deck;
	deck.size = 0;

	deck_init(&deck);

	for (unsigned int i = 0, s = 0; s < deck.size; s += deck.cards[i++].n)
	{
		printf("tile %d [%d/%d]\n",
				i, deck.cards[i].n, deck.size);
		for (int d = 0; d < MAX_DIRECTION; d++)
			printf("->%s\n",
					color_cstring(tile_edge(deck.cards[i].t, d)));

		puts("\n");
	}


	// Free
	// FIXME: It may causes to free a non-malloced-address
	// 		  on thor : ./project # game with updated files
	for (unsigned int i = 0, s = 0; s < deck.size; s += deck.cards[i++].n)
		free((struct tile*)deck.cards[i].t);

//	struct boards board;
//	board_init(&board, deck.cards[1].t); //right now I gave the first tile of the deck,
										 //but il will be a random tile in the futur
	return 0;
}
