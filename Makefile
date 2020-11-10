CFLAGS = -Wall -Wextra -std=c99
DEP = src/utils_color.h src/utils_tile.h src/color.h src/tile.h src/player.h #src/board.h
OBJ = color.o tile.o utils_color.o utils_tile.o player.o #board.o

all: project

project: $(OBJ) tilings.o
	gcc -o project tilings.o $(OBJ)

%.o: src/%.c
	gcc $(CFLAGS) -o $@ -c $<

test: test_tile test_player

test_tile:
	gcc $(CFLAGS) -o test_tile tst/test_tile.c src/tile.c src/utils_color.c src/utils_tile.c src/color.c && ./test_tile
	rm test_tile

test_player:
	gcc $(CFLAGS) -o test_player tst/test_player.c src/player.c src/utils_color.c src/utils_tile.c src/tile.c src/color.c && ./test_player
	rm test_player

clean:
	rm -f *.o

mrproper: clean
	rm project