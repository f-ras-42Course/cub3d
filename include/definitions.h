
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
// # define SCREEN_WIDTH	1920
// # define SCREEN_HEIGHT	1080
// 1280 x 720 (HD)
# define SCREEN_WIDTH	1280
# define SCREEN_HEIGHT	720
// 640 x 360 (ninth HD)
// # define SCREEN_WIDTH	640
// # define SCREEN_HEIGHT	360

# define MINIMAP_GRID_WIDTH		15
# define MINIMAP_GRID_HEIGHT	11

# define BIGMAP_GRID_WIDTH		47
# define BIGMAP_GRID_HEIGHT		35


//-- Tested workable FOVs are: 66.2068965517, 96.00, 101.0526315789, 106.6666666666
# define FOV					66.2068965517
// # define FOV					96.0000000000
// # define FOV					101.0526315789
// # define FOV					106.6666666666

typedef enum e_error_codes
{
	SUCCES,
	// PARSE
	NO_DOT_CUB,
	NO_MAP,
	// GFX
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