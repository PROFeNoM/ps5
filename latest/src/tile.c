#include <stdlib.h>
#include <stdio.h>

#include "tile.h"
#include "color.h"
#include "ansi.h"

#define NUMBER_OF_EDGES 4

struct tile
{
	int i; // Decimal (unique) representation of the Wang tile
	// NOTE: i = ((e_n * C + e_s) * C + e_e) * C + e_w,
	//       with C being the number of colors used in the tile set

	struct color* edges[NUMBER_OF_EDGES]; // Colors of the Wang tile edges
	// NOTE: Colors (as in colors.c > enum colors) are given by
	//       e_n = (i/C^3)%C
	//       e_s = (i/C^2)%C
	//       e_e = (i/C)%C
	//       e_w = i%C
};

// A tile that is empty
const struct tile* empty_tile()
{
	return NULL;
}

// A predicate telling if the tile is empty
int tile_is_empty(const struct tile* t)
{
	return t == NULL;
}

// A comparator between tiles
int tile_equals(const struct tile* t1, const struct tile* t2)
{
	return t1->i == t2->i;
}

// Accessors to the color of the edges
struct color* tile_edge(const struct tile* t, enum direction d)
{
	return t->edges[d];
}

// Return index of a tile in a deck, else -1
int index_of_tile(struct deck* d, const struct tile* t)
{
	for (int i = 0, s = 0; s < d->size; s += d->cards[i++].n)
	{
		if (tile_equals(d->cards[i].t, t))
			return i;
	}
	return -1;
}

// A function that fills a deck with tiles
void deck_init(struct deck* d)
{
	// Just for testing
	const int C = 2 + rand() % (MAX_COLORS - 2); // Number of colors.
	const int MAX_SET_COUNT = C * C * C * C; // A complete set counts C^4 tiles
	printf("NUMBER OF COLORS: %d\n", C);

	int i = 0;
	while (d->size < MAX_DECK_SIZE && d->size < MAX_SET_COUNT)
	{
		int index = rand() % MAX_SET_COUNT;

		struct tile* t = malloc(sizeof(struct tile));
		t->i = index;
		t->edges[NORTH] = color_from_name(colors_names[(index / (C * C * C)) % C]);
		t->edges[SOUTH] = color_from_name(colors_names[(index / (C * C)) % C]);
		t->edges[EAST] = color_from_name(colors_names[(index / C) % C]);
		t->edges[WEST] = color_from_name(colors_names[index % C]);

		int is_in_deck = index_of_tile(d, t);

		if (is_in_deck == -1)
		{
			struct deck_pair p = { t, 1 };

			d->cards[i] = p;
			i++;
		}
		else
		{
			for (int c = 0; c < MAX_DIRECTION; c++)
				free(t->edges[c]);
			free(t);
			d->cards[is_in_deck].n++;
		}

		d->size++;
	}
}