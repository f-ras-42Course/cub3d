/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   object_change.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 19:28:53 by fras          #+#    #+#                 */
/*   Updated: 2024/11/08 19:28:55 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	close_door(int x, int y)
{
	map_data(CHANGE_ELEMENT, x, y, 'D');
}

void	open_door(int x, int y)
{
	map_data(CHANGE_ELEMENT, x, y, 'O');
}
