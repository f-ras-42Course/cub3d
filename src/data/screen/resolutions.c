
#include "data.h"

t_resolutions		set_resolution(t_resolutions set)
{
	static t_resolutions	resolution;


	if (set == GET_RESOLUTION)
		return (resolution);
	resolution = set;
	return (resolution);
}

int		screen_width(void)
{	
	const static int	screen_width[SUPPORTED_RESOLUTIONS] = {
	[R_8K] = 7680,
	[R_4K] = 3840,
	[R_WQXGAPLUS] = 3200,
	[R_QUAD_HD] = 2560,
	[R_FULL_HD] = 1920,
	[R_HD] = 1280,
	[R_NINTH_HD] = 640};

	return (screen_width[set_resolution(GET_RESOLUTION)]);
}

int		screen_height(void)
{
	const static int	screen_height[SUPPORTED_RESOLUTIONS] = {
	[R_8K] = 4320,
	[R_4K] = 2160,
	[R_WQXGAPLUS] = 1800,
	[R_QUAD_HD] = 1440,
	[R_FULL_HD] = 1080,
	[R_HD] = 720,
	[R_NINTH_HD] = 360};

	return (screen_height[set_resolution(GET_RESOLUTION)]);
}

void	decrease_resolution(t_gfx_data *graphics)
{
	const t_resolutions	old_resolution = set_resolution(GET_RESOLUTION);
	if (old_resolution == 0)
	{
		cub3d_float_int_printer(STDOUT_FILENO, \
						"Screen resolution already at lowest (%d x %d)\n", \
						screen_width(), screen_height());
		return ;
	}
	set_resolution(old_resolution - 1);
	if (old_resolution - 1 == DEFAULT_RESOLUTION)
		cub3d_float_int_printer(STDOUT_FILENO, "(default) ");
	cub3d_float_int_printer(STDOUT_FILENO, "Screen Resolution set to: %d x %d"\
							"\n", screen_width(), screen_height());
	resize_all(graphics);
}

void	increase_resolution(t_gfx_data *graphics)
{
	const t_resolutions	old_resolution = set_resolution(GET_RESOLUTION);

	if (old_resolution == SUPPORTED_RESOLUTIONS)
	{
		cub3d_float_int_printer(STDOUT_FILENO, \
						"Screen resolution already at heighest (%d x %d)\n", \
						screen_width(), screen_height());
		return ;
	}
	keep_within_monitor_limit(set_resolution(old_resolution + 1));
	if (set_resolution(GET_RESOLUTION) == DEFAULT_RESOLUTION)
		cub3d_float_int_printer(STDOUT_FILENO, "(default) ");
	cub3d_float_int_printer(STDOUT_FILENO, "Screen Resolution set to: %d x %d"\
							"\n", screen_width(), screen_height());
	resize_all(graphics);
}
