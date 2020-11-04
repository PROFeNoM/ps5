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

	struct deck *deck = malloc(sizeof(struct deck));

	deck_init(deck);

	for (int i = 0; i < deck->size; i++)
	{
		printf("tile %d\n", i);
		printf("->%s\n", color_cstring(tile_edge(deck->cards[i].t, NORTH)));
		printf("->%s\n", color_cstring(tile_edge(deck->cards[i].t, SOUTH)));
		printf("->%s\n", color_cstring(tile_edge(deck->cards[i].t, EAST)));
		printf("->%s\n", color_cstring(tile_edge(deck->cards[i].t, WEST)));

		puts("\n");
	}

	return 0;
}