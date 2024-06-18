
#include "cub3d.h"

bool	ft_iswhitespace(int c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	get_rgb(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}
