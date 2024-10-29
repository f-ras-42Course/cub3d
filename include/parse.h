
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

t_str	*str_new(char *s);
void	str_add_back(t_str **head, t_str *new);
void	free_str(t_str *head);

char	*get_set(char cell);
bool	is_valid_neighbour(t_all *data, size_t x, size_t y, char *set);
bool	open_file(t_all *data, char *map, int *fd);
void	init_map_data(t_map *map, t_player *player);
bool	is_valid_file(t_all *data, char *map_name, int argc);

bool	is_valid_map(t_all *data);
bool	get_elements(t_all *data, int fd);
bool	parse_map(t_all *data, int argc, char *map_name);
bool	get_map(t_all *data, int fd, char *line);

#endif

