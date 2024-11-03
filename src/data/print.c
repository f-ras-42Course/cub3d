
#include "data.h"

void	test_print_map(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}
