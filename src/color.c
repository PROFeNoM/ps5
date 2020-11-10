#include "utils_color.h"

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
	return colored_names[t->c];
}

// Return a color from its name, or NULL
struct color* color_from_name(const char* name)
{
	for (int i = 0; i < MAX_COLORS; i++)
		if (strcmp(name, colors_names[i]) == 0)
			return &colors_struct[i];

	return NULL;
}