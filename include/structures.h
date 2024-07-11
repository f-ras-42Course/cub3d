#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "MLX42/MLX42.h"

typedef struct s_player
{
	double		position[2];
	double		direction;
	double		plane[2];
}				t_player;

typedef struct s_ray
{
	double		direction;
	double		delta[2];
	double		shortest[2];
	int			check_pos[2];
}				t_ray;

typedef struct s_map
{
	char		**map;
	char		*north_texture;
	char		*south_texture;
	char		*east_texture;
	char		*west_texture;
	int			index[2];
}				t_map;

typedef struct s_fps
{
	double		time;
	double		old_time;
}				t_fps;


/*  minimap_width:
	Full HD: 225 | 4K: 450
	minimap_height:
	Full HD: 165 | 4K: 330
	minimap_unit_size:
	Full HD: 15 | 4K: 30
*/
typedef struct s_minimap
{
	mlx_image_t	*image;
	int			width;
	int			height;
	int			frame_thickness;
	int			unit_size;
	int			end_of_map_locator_x;
	int			end_of_map_locator_y;
	t_player	*player;
}	t_minimap;


typedef struct s_bigmap
{
	mlx_image_t	*image;
	int			width;
	int			height;
	int			unit_size;
	t_player	*player;
}	t_bigmap;


typedef struct s_mainlayer
{
	mlx_image_t	*image;
	t_player	*player;
}	t_mainlayer;

typedef struct s_gfx_data
{
	mlx_t			*mlx;
	t_mainlayer		mainlayer;
	t_minimap		minimap;
	t_bigmap		bigmap;
	struct s_all	*data;
}	t_gfx_data;

typedef struct s_all
{
	t_player	player;
	t_ray		ray;
	t_map		map;
	t_fps		fps;
	t_gfx_data	graphics;
	int			error_code;
}				t_all;

#endif