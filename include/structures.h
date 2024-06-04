#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct	s_player
{
	int			position[2];
	int			direction[2];
	int			plane[2];
}				t_player;

typedef struct	s_ray
{
	int			side_dist[2];
	int			delta_dist[2];
	int			hit;
	int			side;
}				t_ray;

typedef struct	s_map
{
	int			**map;
	int			index[2];
}				t_map;

typedef struct	s_fps
{
	double		time;
	double		old_time;
}				t_fps;

typedef struct	s_data
{
	t_player	player;
	t_ray		ray;
	t_map		map;
	t_fps		fps;
}				t_data;


#endif