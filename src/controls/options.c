/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   options.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 19:17:56 by fras          #+#    #+#                 */
/*   Updated: 2024/11/08 19:19:07 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
		printf("(default) ");
	printf("FOV set to: %d\n", (int)data->player.fov);
}

void	zoom_in(t_all *data)
{
	static double	old_fov;

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

void	fps_print_ioswitch(t_fps *fps)
{
	if (fps->printing_enabled)
		fps->printing_enabled = false;
	else
		fps->printing_enabled = true;
}

void	fps_screen_ioswitch(t_gfx_data *graphics, t_fps *fps)
{
	int	i;

	i = 0;
	if (fps->on_screen_enabled)
	{
		fps->on_screen_enabled = false;
		while (i <= MAX_SCREEN_FPS)
			graphics->fps_on_screen[i++]->enabled = false;
	}
	else
		fps->on_screen_enabled = true;
}
