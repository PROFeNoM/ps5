#include "utils_tile.h"

// TODO: Find a way not to use malloc
// Return a tile from its parameters
struct tile* make_tile(int c_n, int c_s, int c_e, int c_w)
{
	struct tile* t = malloc(sizeof(struct tile));
	int index = ((c_n * C + c_s) * C + c_e) * C + c_w;

	t->i = index;

	t->edges[NORTH] = &colors_struct[c_n];
	t->edges[SOUTH] = &colors_struct[c_s];
	t->edges[EAST] = &colors_struct[c_e];
	t->edges[WEST] = &colors_struct[c_w];

	return t;
}