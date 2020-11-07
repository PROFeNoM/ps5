#include <stdlib.h>
#include <stdio.h>

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
	// Just for testing
	const int C = 2 + rand() % (MAX_COLORS - 2); // Number of colors.
	const unsigned int MAX_SET_COUNT = C * C * C * C; // A complete set counts C^4 tiles
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
			d->cards[is_in_deck].n++;

		d->size++;
	}
}


void board_init(struct boards* board, const struct tile *t)
{

    for (int i = 0 ; i < BOARD_LENTH ; i++){
        for (int j = 0 ; j < BOARD_LENTH ; j++){
            board->dispo[i][j] = 0;
            board->mat_of_tile[i][j] = 0;
        }
    }
    // on place ici une première tuile aléatoire (voir la méthode employé en fin de séance) au milieu du plateau
    int middle = BOARD_LENTH/2;
    int C = 20; // c'est pas bon mais c'est tant qu'on a pas généralisé la décla de C

    board->dispo[middle][middle] = 80;
    board->mat_of_tile[middle][middle] = t->i;

    board->dispo[middle+1][middle]+=27;
    board->mat_of_tile[middle+1][middle]+= (C*C*C*(t->i)/ (C*C*C)) %C; //ces calculs sont à revoir

    board->dispo[middle-1][middle]+=9;
    board->mat_of_tile[middle-1][middle]+= (C*C*(t->i)/ (C*C)) %C;

    board->dispo[middle][middle-1]+=3;
    board->mat_of_tile[middle][middle-1]+= (C*(t->i)/C) %C;

    board->dispo[middle][middle+1]+=1;
    board->mat_of_tile[middle][middle+1]+=t->i % C;
    /*for (int i = 0 ; i < BOARD_LENTH ; i++){
        for (int j = 0 ; j < BOARD_LENTH ; j++){
            printf("%d ", board->dispo[i][j]);
        }
        printf("\n");
    }
    for (int i = 0 ; i < BOARD_LENTH ; i++){
        for (int j = 0 ; j < BOARD_LENTH ; j++){
            printf("%d ", board->mat_of_tile[i][j]);
        }
        printf("\n");
    }*/
}
