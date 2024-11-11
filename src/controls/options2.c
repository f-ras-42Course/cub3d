/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   options2.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/11 15:31:44 by fras          #+#    #+#                 */
/*   Updated: 2024/11/11 15:42:13 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	fps_ioswitch(t_gfx_data *graphics, t_fps *fps)
{
	fps_print_ioswitch(fps);
	fps_screen_ioswitch(graphics, fps);
}

void	mouse_rotation_ioswitch(t_gfx_data *graphics)
{
	if (graphics->mouse_rotation_enabled)
	{
		mlx_set_cursor_mode(graphics->mlx, MLX_MOUSE_NORMAL);
		graphics->mouse_rotation_enabled = false;
	}
	else
	{
		mlx_set_mouse_pos(graphics->mlx, \
						screen_width() / 2, screen_height() / 2);
		mlx_set_cursor_mode(graphics->mlx, MLX_MOUSE_DISABLED);
		graphics->mouse_rotation_enabled = true;
	}
}
