#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct	player_data
{
	int			position[2];
	int			direction[2];
	int			plane[2];
};

typedef struct	ray_data
{
	int			side_dist[2];
	int			delta_dist[2];
	int			hit;
	int			side;
};

typedef struct	map_data
{
	int			**map;
	int			index[2];
};

typedef struct	fps
{
	double		time;
	double		old_time;
};

#endif