#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "MLX42/MLX42.h"

typedef struct s_player
{
	double		position[2];
	double		direction[2];
	double		plane[2];
}				t_player;

typedef struct s_ray
{
	double		side_dist[2];
	double		delta_dist[2];
	bool		hit;
	bool		side;
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


/*	Full HD: 225	| 4K: 450
	int	minimap_width;
	Full HD: 165	| 4K: 330
	int	minimap_height;
	Full HD: 5	| 4K: 10
	int	minimap_frame_thickness;
	Full HD: 15 	| 4K: 30
	int	minimap_unit_size;
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

typedef struct s_gfx_data
{
	mlx_t			*mlx;
	mlx_image_t		*background;
	t_minimap		minimap;
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