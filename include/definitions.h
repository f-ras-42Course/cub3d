#ifndef DEFINITIONS_H
# define DEFINITIONS_H

# ifndef DEBUG
#  define DEBUG 0
# endif

# define SCREEN_WIDTH	1440
# define SCREEN_HEIGHT	900

typedef enum e_error_codes
{
	SUCCES,
	// PARSE
	NO_MAP,
	// GFX
	MLX_CRASH,
}	t_error_codes;


enum e_rectangle_measures
{
	RECT_WIDTH,
	RECT_HEIGHT,
	DRAW_POS_X,
	DRAW_POS_Y
};

#endif
