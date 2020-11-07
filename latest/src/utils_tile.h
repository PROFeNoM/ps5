#ifndef _UTILS_TILE_H
#define _UTILS_TILE_H

#include "tile.h"
#include "utils_color.h"

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

// Empty tile used to compare memory addresses
static const struct tile an_empty_tile = { };

// TODO: make_tile() to make it easier creating tiles
// Return a tile from its parameters
struct tile* make_tile(int C, int c_n, int c_s, int c_e, int c_w);

#endif // _UTILS_TILE_H
