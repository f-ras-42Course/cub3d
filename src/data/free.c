
#include "data.h"

void	free_cub_data(t_map *cub)
{
	free_double_pointer(cub->map);
	free(cub->north_texture);
	free(cub->east_texture);
	free(cub->south_texture);
	free(cub->west_texture);
}
