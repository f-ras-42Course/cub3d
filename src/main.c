/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 19:17:32 by fras          #+#    #+#                 */
/*   Updated: 2024/11/08 19:17:35 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_all	data;

	if (!parse_map(&data, argc, argv[1]))
		return (data.error_code);
	if (!set_data(&data) || \
		!init_graphics(&data) || \
		!load_hooks(&data))
	{
		free_cub_data(&data.map);
		return (data.error_code);
	}
	run_graphics(&data);
	free_cub_data(&data.map);
	return (SUCCES);
}
