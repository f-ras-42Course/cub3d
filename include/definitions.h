
#ifndef DEFINITIONS_H
# define DEFINITIONS_H

# ifndef DEBUG
#  define DEBUG 0
# endif

# define MINIMAP_GRID_WIDTH		15
# define MINIMAP_GRID_HEIGHT	11

/*
 * Choose one of the following options:
 - R_8K
 - R_4K
 - R_WQXGAPLUS
 - R_QUAD_HD
 - R_FULL_HD
 - R_HD
 - R_NINTH_HD
 */
# define DEFAULT_RESOLUTION		R_HD
# define SUPPORTED_RESOLUTIONS	7

/*Workable FOVs are formulated below:
 * - (with star '*' is choosable in game)
 *										32.0000000000
 *										64.0000000000
 *										*66.2068965517
 *										*96.0000000000
 *										*101.0526315789
 *										104.0000000000
 *										*106.6666666666
 *										128.0000000000
 */
# define DEFAULT_FOV					66.2068965517

# define MAX_SCREEN_FPS					120

typedef enum e_resolutions
{
	R_NINTH_HD,
	R_HD,
	R_FULL_HD,
	R_QUAD_HD,
	R_WQXGAPLUS,
	R_4K,
	R_8K,
	GET_RESOLUTION
}	t_resolutions;

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

typedef enum e_xyz
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

typedef	enum	e_mapaccess
{
	GET,
	SET,
	CHANGE_ELEMENT
}	t_mapaccess;

#endif