#ifndef _COLOR_H_
#define _COLOR_H_

struct color; // Anonymous struct for colors

// A string giving the color name
const char* color_name(struct color* t);
// An ANSI-colored string describing the color
const char* color_cstring(struct color* t);
// Return a color from its name, or NULL
struct color* color_from_name(const char* name);

#endif // _COLOR_H_