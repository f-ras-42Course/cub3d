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

#endif
