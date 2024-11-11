/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structures.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 18:14:10 by fras          #+#    #+#                 */
/*   Updated: 2024/11/11 19:01:41 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "MLX42/MLX42.h"
# include "definitions.h"

typedef struct s_player
{
	double		position[2];
	double		direction;
	double		fov;
}				t_player;

typedef struct s_ray
{
	double		direction;
	double		delta[2];
	double		shortest[2];
	int			check_pos[2];
	t_nesw		side;
	bool		is_door_closed;
	bool		is_door_open;
}				t_ray;

typedef struct s_map
{
	char		**map;
	size_t		size[2];
	char		*north_texture;
	char		*south_texture;
	char		*east_texture;
	char		*west_texture;
	int			floor_color;
	int			ceiling_color;
	int			player_location[2];
}				t_map;

typedef struct s_fps
{
	double		old_time;
	double		time;
	bool		printing_enabled;
	bool		on_screen_enabled;
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
	size_t		end_of_map_locator_x;
	size_t		end_of_map_locator_y;
	t_player	*player;
}				t_minimap;

typedef struct s_bigmap
{
	mlx_image_t	*image;
	int			width;
	int			height;
	int			unit_size;
	t_player	*player;
}				t_bigmap;

typedef struct s_textures
{
	mlx_texture_t	*north_texture;
	mlx_texture_t	*south_texture;
	mlx_texture_t	*east_texture;
	mlx_texture_t	*west_texture;
	mlx_texture_t	*door_closed_texture;
	mlx_texture_t	*door_open_texture;
}					t_textures;

typedef struct s_mainlayer
{
	mlx_image_t	*image;
	t_player	*player;
	t_textures	textures;
	uint32_t	floor_color;
	uint32_t	ceiling_color;
}				t_mainlayer;

typedef struct s_doorlayer
{
	mlx_image_t	*image;
	t_player	*player;
	t_textures	*textures;
}				t_doorlayer;

typedef struct s_gfx_data
{
	mlx_t			*mlx;
	t_mainlayer		mainlayer;
	t_minimap		minimap;
	t_bigmap		bigmap;
	t_doorlayer		doorlayer;
	mlx_image_t		*fps_on_screen[MAX_SCREEN_FPS + 1];
	struct s_all	*data;
	bool			mouse_rotation_enabled;
}					t_gfx_data;

typedef struct s_wall_data
{
	double			ray_distance;
	double			perp_distance;
	double			step[2];
	int				wall_height;
	int				line_height;
	int				tex[2];
	int				start_x;
	int				start_y;
	t_ray			*ray;
	t_player		*player;
}					t_wall_data;

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