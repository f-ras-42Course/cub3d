/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   object_check.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 19:28:57 by fras          #+#    #+#                 */
/*   Updated: 2024/11/08 19:47:36 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

bool	wall_found(int x, int y)
{
	char	**map;

	map = map_data(GET);
	return (map[y][x] == '1');
}

bool	closed_door_found(int x, int y)
{
	char	**map;

	map = map_data(GET);
	return (map[y][x] == 'D');
}

bool	open_door_found(int x, int y)
{
	char	**map;

	map = map_data(GET);
	return (map[y][x] == 'O');
}
