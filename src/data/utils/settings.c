/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   settings.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 19:28:29 by fras          #+#    #+#                 */
/*   Updated: 2024/11/08 19:29:21 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	set_position(double x, double y, double where[2])
{
	where[X] = x;
	where[Y] = y;
}
