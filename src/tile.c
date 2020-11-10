#include "utils_tile.h"


// A tile that is empty
const struct tile* empty_tile()
{
	return &an_empty_tile;
}

// A predicate telling if the tile is empty
int tile_is_empty(const struct tile* t)
{
	return t == NULL || t == &an_empty_tile;
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
	for (unsigned int i = 0, s = 0; s < d->size; s += d->cards[i++].n)
	{
		if (tile_equals(d->cards[i].t, t))
			return i;
	}
	return -1;
}

// A function that fills a deck with tiles
void deck_init(struct deck* d)
{
	//const int C = 2 + rand() % (MAX_COLORS - 2); // Number of colors.
	const unsigned int MAX_SET_COUNT = C * C * C * C; // A complete set counts C^4 tiles
	printf("NUMBER OF COLORS: %d\n", C);

	int i = 0;
	while (d->size < MAX_DECK_SIZE && d->size < MAX_SET_COUNT)
	{
		int index = rand() % MAX_SET_COUNT;

		struct tile* t = make_tile(
				(index / (C * C * C)) % C,
				(index / (C * C)) % C,
				(index / C) % C,
				index % C);

		int is_in_deck = index_of_tile(d, t);

		if (is_in_deck == -1)
			d->cards[i++] = (struct deck_pair){ t, 1 };
		else
		{
			d->cards[is_in_deck].n++;
			free(t);
		}
		d->size++;
	}
}
