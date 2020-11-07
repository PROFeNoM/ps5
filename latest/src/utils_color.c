#include "utils_color.h"

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

struct color colors_struct[MAX_COLORS] =
		{
				{ BLACK, "BLACK" },
				{ RED, "RED" },
				{ GREEN, "GREEN" },
				{ YELLOW, "YELLOW" },
				{ BLUE, "BLUE" },
				{ MAGENTA, "MAGENTA" },
				{ CYAN, "CYAN" },
				{ WHITE, "WHITE" },
				{ NAVY, "NAVY" },
				{ DARK_GREEN, "DARK_GREEN" },
				{ DARK_RED, "DARK_RED" },
				{ PURPLE, "PURPLE" },
				{ BROWN, "BROWN" },
				{ KAKHI, "KAKHI" },
				{ PALE_BLUE, "PALE_BLUE" },
				{ PALE_PURPLE, "PALE_PURPLE" },
				{ ORANGE, "ORANGE" },
				{ PALE_GREEN, "PALE_GREEN" },
				{ PINK, "PINK" },
				{ GOLDEN, "GOLDEN" }
		};


char* colored_names[] =
		{ "\e[0;30mBLACK\e[0m", "\e[0;31mRED\e[0m", "\e[0;32mGREEN\e[0m", "\e[0;33mYELLOW\e[0m",
		  "\e[0;34mBLUE\e[0m", "\e[0;35mMAGENTA\e[0m", "\e[0;36mCYAN\e[0m", "\e[0;37mWHITE\e[0m",
		  "\e[38;5;18mNAVY\e[0m", "\e[38;5;22mDARK_GREEN\e[0m", "\e[38;5;52mDARK_RED\e[0m", "\e[38;5;55mPURPLE\e[0m",
		  "\e[38;5;94mBROWN\e[0m", "\e[38;5;100mKAKHI\e[0m", "\e[38;5;110mPALE_BLUE\e[0m", "\e[38;5;147mPALE_PURPLE\e[0m",
		  "\e[38;5;166mORANGE\e[0m", "\e[38;5;193mPALE_GREEN\e[0m", "\e[38;5;200mPINK\e[0m", "\e[38;5;220mGOLDEN\e[0m" };
