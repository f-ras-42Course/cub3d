
#ifndef PARSE_H
# define PARSE_H

# include <fcntl.h>
# include <stdbool.h>
# include "structures.h"

bool	parse_map(t_all *data, char *map_name);

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

