
#ifndef PARSE_H
# define PARSE_H

# include <fcntl.h>
# include <stdbool.h>
# include "structures.h"

typedef struct		s_str
{
	char			*str;
	size_t			len;
	struct s_str	*next;
}					t_str;

t_str	*strnew(char *s);
void	straddback(t_str **head, t_str *new);
void	free_str(t_str *head);

char	*get_elements(t_all *data, int fd);
bool	parse_map(t_all *data, int argc, char *map_name);
bool	get_map(t_all *data, int fd, char *line);

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

