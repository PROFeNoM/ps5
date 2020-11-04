#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "color.h"
#include "ansi.h"

char* colors_names[] =
		{ "BLACK", "RED", "GREEN", "YELLOW",
		  "BLUE", "MAGENTA", "CYAN", "WHITE",
		  "NAVY", "DARK_GREEN", "DARK_RED", "PURPLE",
		  "BROWN", "KAKHI", "PALE_BLUE", "PALE_PURPLE",
		  "ORANGE", "PALE_GREEN", "PINK", "GOLDEN" };

char* colors_ansi[] =
		{ "\e[0;30m", "\e[0;31m", "\e[0;32m", "\e[0;33m",
		  "\e[0;34m", "\e[0;35m", "\e[0;36m", "\e[0;37m",
		  "\e[38;5;18m", "\e[38;5;22m", "\e[38;5;52m", "\e[38;5;55m",
		  "\e[38;5;94m", "\e[38;5;100m", "\e[38;5;110m", "\e[38;5;147m",
		  "\e[38;5;166m", "\e[38;5;193m", "\e[38;5;200m", "\e[38;5;220m" };

struct color
{
	int c; // Decimal representation of the color
	char* name; // Name of the color
};

// An ANSI color code describing the color
const char* ansi_code(struct color* t)
{
	return colors_ansi[t->c];
}

// A string giving the color name
const char* color_name(struct color* t)
{
	return t->name;
}

// An ANSI-colored string describing the color
const char* color_cstring(struct color* t)
{
	char* cstring;

	asprintf(&cstring, "%s%s%s", ansi_code(t), color_name(t), RESET);

	return cstring;
}

// Return a color from its name, or NULL
struct color* color_from_name(const char* name)
{
	for (int i = 0; i < MAX_COLORS; i++)
		if (strcmp(name, colors_names[i]) == 0)
		{
			struct color* color = malloc(sizeof(struct color*));
			color->c = i;
			color->name = colors_names[i];

			return color;
		}

	return NULL;
}