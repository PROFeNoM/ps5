#ifndef _UTILS_COLOR_H_
#define _UTILS_COLOR_H_

#include "color.h"

#define MAX_COLORS 20
#define RESET "\e[0m"

struct color
{
	int c; // Decimal representation of the color
	char* name; // Name of the color
};

enum colors
{
	BLACK, RED, GREEN, YELLOW,
	BLUE, MAGENTA, CYAN, WHITE,
	NAVY, DARK_GREEN, DARK_RED, PURPLE,
	BROWN, KAKHI, PALE_BLUE, PALE_PURPLE,
	ORANGE, PALE_GREEN, PINK, GOLDEN,
};

// An array of the color names
extern char* colors_names[];

// An array of the ANSI code respectively to its' color name
extern char* colors_ansi[];

// An array of the ANSI-colored colors name
extern char* colored_names[];

// An array of preset structs relative to each colors
extern struct color colors_struct[MAX_COLORS];

#endif // _UTILS_COLOR_H_