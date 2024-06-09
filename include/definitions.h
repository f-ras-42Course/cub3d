
#ifndef DEFINITIONS_H
# define DEFINITIONS_H

# ifndef DEBUG
#  define DEBUG 0
# endif

# define SCREEN_WIDTH	1920
# define SCREEN_HEIGHT	1080

/* Currently: 241 */
extern const int	g_minimap_width;
/* Currently: 177 */
extern const int	g_minimap_height;
/* Currently: 5 */
extern const int	g_minimap_frame_thickness;

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
	frame_only
}	t_minimap_options;

#endif