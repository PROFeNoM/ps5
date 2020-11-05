#ifndef _ANSI_H_
#define _ANSI_H_

#define MAX_COLORS 20
#define RESET "\e[0m"


enum colors // It may be useless...
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

#endif // _ANSI_H_