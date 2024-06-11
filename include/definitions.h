
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

/* Full HD: 225	| 4K: 450 */
extern const int	g_minimap_width;
/* Full HD: 165	| 4K: 330 */
extern const int	g_minimap_height;
/* Full HD: 5	| 4K: 10 */
extern const int	g_minimap_frame_thickness;
/* Full HD: 15 	| 4K: 30*/
extern const int	g_minimap_unit_size;




typedef enum e_error_codes
{
	SUCCES,
	// PARSE
	NO_DOT_CUB,
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

enum	e_xyz
{
	X,
	Y,
	Z
};

typedef enum e_minimap_options
{
	raster_only,
	raster_plus_frame,
	frame_only,
	fill_end_of_map
}	t_minimap_options;

#endif