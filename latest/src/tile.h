#ifndef _TILE_H_
#define _TILE_H_

#include "color.h"

enum direction
{
	NORTH, SOUTH, EAST, WEST,
	MAX_DIRECTION, ERROR_DIRECTION = -1
};

struct tile; // Anonymous struct for tiles

#define MAX_DECK_SIZE 100
struct deck_pair
{
	const struct tile* t;
	unsigned int n;
};

struct deck
{
	struct deck_pair cards[MAX_DECK_SIZE];
	unsigned int size;
};

// A tile that is empty
const struct tile* empty_tile();

// A predicate telling if the tile is empty
int tile_is_empty(const struct tile* t);

// A comparator between tiles
int tile_equals(const struct tile* t1, const struct tile* t2);

// Accessors to the color of the edges
struct color* tile_edge(const struct tile* t, enum direction d);

// A function that fills a deck with tiles
void deck_init(struct deck* d);


// while we don't add it in param, i define hear the board lenth equal to 50
#define BOARD_LENTH 10

struct boards
{
	int mat_of_tile[BOARD_LENTH][BOARD_LENTH];
	int dispo[BOARD_LENTH][BOARD_LENTH];      //both will be combine in a 3 dimension array
};
//the board will be defined with 2 matrice of on numbers which represent emplacement for tiles
//the first have the information on the color on each of its edges
//The second matrice, dispo, is made of numbers named here, "d", wich countain the information
//of the disponibility of an edge of the corresponding emplacement
//the disponibility of an edge can be obtain form d with :
   //dipo_north = d/(3*3*3) %3
   //d_s = d/(3*3) %3
   //d_e = d/3 %3
   //d_w = d %3
   //d_? = "0" means that the edge is disponible, "1" that it isn't, and 2 that the emplacement is already taken
   //for example d=0 means that all edges are dispo.,
   //d=1 means that a special color is required on the west edge,
   //d=80 means that the emplacement is taken
   //NOTE: so to add a dependance on north : +27, on south : +9, on east : +3, on west : +1
//
//an edge that is disponible may countain a random color but it will be ignored when trying to find a matching tile

void board_init(struct boards *board, const struct tile *t);

#endif // _TILE_H_
