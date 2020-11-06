CFLAGS = -Wall -Wextra -std=c99

all: project

project: tile.o color.o main.o
	gcc -o project main.o color.o tile.o

#tile.o: src/tile.c src/ansi.h
#	gcc $(CFLAGS) -o tile.o -c src/tile.c

#color.o: src/color.c src/ansi.h
#	gcc $(CFLAGS) -o color.o -c src/color.c

#main.o: src/main.c src/color.h src/tile.h
#	gcc $(CFLAGS) -o main.o -c src/main.c

%.o: src/%.c
	gcc $(CFLAGS) -o $@ -c $<

clean:
	rm -f *.o

mrproper: clean
	rm project