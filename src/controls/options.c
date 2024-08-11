
#include "data.h"

void	change_fov(t_all *data)
{
	if (data->player.fov == 66.2068965517)
		data->player.fov = 96.0000000000;
	else if (data->player.fov == 96.0000000000)
		data->player.fov = 101.0526315789;
	else if (data->player.fov == 101.0526315789)
		data->player.fov = 106.6666666666;
	else
		data->player.fov = 66.2068965517;
	if (data->player.fov == DEFAULT_FOV)
		cub3d_float_int_printer(STDOUT_FILENO, "(default) ", (int)data->player.fov);
	cub3d_float_int_printer(STDOUT_FILENO, "FOV set to: %d\n", (int)data->player.fov);
}

void	zoom_in(t_all *data)
{
	static double old_fov;

	if (data->player.fov != 16)
	{
		old_fov = data->player.fov;
		data->player.fov = 16.0000000000;
	}
	else
		data->player.fov = old_fov;
}

void	bigmap_io_switch(t_bigmap *bigmap)
{
	if (bigmap->image->enabled)
		bigmap->image->enabled = false;
	else
		bigmap->image->enabled = true;
}

void	testmode_io_switch(t_gfx_data *graphics)
{
	if (graphics->testmode)
		graphics->testmode = false;
	else
		graphics->testmode = true;
}

void	fps_ioswitch(t_fps *fps)
{
	if (fps->enabled)
		fps->enabled = false;
	else
		fps->enabled = true;
}
