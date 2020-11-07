CFLAGS = -Wall -Wextra -std=c99
DEP = src/utils_color.h src/utils_tile.h src/color.h src/tile.h src/player.h
OBJ = utils_color.o color.o tile.o player.o

all: project

project: $(OBJ) tilings.o
	gcc -o project tilings.o utils_color.o color.o tile.o

%.o: src/%.c $(DEP)
	gcc $(CFLAGS) -o $@ -c $<

test: test_tile test_player

test_tile:
	gcc $(CFLAGS) -o test_tile tst/test_tile.c src/tile.c src/utils_color.c src/color.c && ./test_tile
	rm test_tile

test_player:
	gcc $(CFLAGS) -o test_player tst/test_player.c src/tile.c src/utils_color.c src/color.c && ./test_player
	rm test_player

clean:
	rm -f *.o

mrproper: clean
	rm project