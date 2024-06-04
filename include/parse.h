
#ifndef PARSE_H
# define PARSE_H

# include <fcntl.h>
# include "structures.h"

int	parse_map(t_data *all, char *map_name);

/*
one struct with all data or multiple structs
- player data
	-position (x, y)
	-direction (x, y)
	-plane (x, y)

- map data
	-2d array for map (int *)
	-mapcoordinates (x, y)

- ray data
	-sidedistance (x, y)
	-deltadistance (x, y)
	-hit (binary)
	-side (binary)
*/

#endif

