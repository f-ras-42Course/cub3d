
#ifndef DEFINITIONS_H
# define DEFINITIONS_H

# ifndef DEBUG
#  define DEBUG 0
# endif

/* supported resolutions */

// 7680 x 4320 (8K)
// # define SCREEN_WIDTH	7680
// # define SCREEN_HEIGHT	4320
// 3200 x 1800 (4K)
// # define SCREEN_WIDTH	3840
// # define SCREEN_HEIGHT	2160
// 3200 x 1800 (WQXGA+)
// # define SCREEN_WIDTH	3200
// # define SCREEN_HEIGHT	1800
// 2560 x 1440 (Quad HD)
// # define SCREEN_WIDTH	2560
// # define SCREEN_HEIGHT	1440
// 1920 x 1080 (Full HD)
# define SCREEN_WIDTH	1920
# define SCREEN_HEIGHT	1080
// 1280 x 720 (HD)
// # define SCREEN_WIDTH	1280
// # define SCREEN_HEIGHT	720
// 640 x 360 (ninth HD)
// # define SCREEN_WIDTH	640
// # define SCREEN_HEIGHT	360

# define MINIMAP_GRID_WIDTH		15
# define MINIMAP_GRID_HEIGHT	11

# define BIGMAP_GRID_WIDTH		47
# define BIGMAP_GRID_HEIGHT		35


/*-- 				Workable FOVs are formulated below:
/										32.0000000000
/										64.0000000000
/										66.2068965517
/										96.0000000000
/										101.0526315789
/										104.0000000000
/										106.6666666666
/										128.0000000000*/
//# define DEFAULT_FOV					66.2068965517 -- definition not in use

typedef enum e_error_codes
{
	SUCCES,
	// PARSE
	INVALID_MAP,
	MAP_TOO_SMALL,
	NO_PLAYER,
	INVALID_CHARACTER,
	MULTIPLE_PLAYERS,
	REPEATING_ELEMENTS,
	NOT_ALL_ELEMENTS,
	RGB,
	NO_SUCH_FILE,
	NO_DOT_CUB,
	NO_MAP,
	// GFX
	TEXTURE_NO_PNG,
	TEXTURE_LOAD_FAILED,
	MLX_GFX_CRASH,
	MLX_HOOKS_CRASH
}	t_error_codes;


enum e_rectangle_measures
{
	RECT_WIDTH,
	RECT_HEIGHT,
	DRAW_POS_X,
	DRAW_POS_Y
};

enum e_circle_measures
{
	RADIUS,
	DRAW_POS_CENTER_X,
	DRAW_POS_CENTER_Y
};

typedef enum	e_xyz
{
	X,
	Y,
	Z
}	t_xyz;

typedef enum e_nesw
{
	N,
	E,
	S,
	W
}	t_nesw;

typedef enum e_minimap_options
{
	raster_only,
	raster_plus_frame,
	frame_only,
	fill_end_of_map
}	t_minimap_options;

#endif