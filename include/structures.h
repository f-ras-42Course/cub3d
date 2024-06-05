#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_player
{
	int			position[2];
	int			direction[2];
	int			plane[2];
}				t_player;

typedef struct s_ray
{
	int			side_dist[2];
	int			delta_dist[2];
	bool		hit;
	bool		side;
}				t_ray;

typedef struct s_map
{
	int			**map;
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

typedef struct s_all
{
	t_player	player;
	t_ray		ray;
	t_map		map;
	t_fps		fps;
	int			error_code;
}				t_all;


#endif