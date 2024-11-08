/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 19:22:50 by fras          #+#    #+#                 */
/*   Updated: 2024/11/08 19:23:11 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	init_default_resolution(void)
{
	set_resolution(DEFAULT_RESOLUTION);
	printf("Default Screen Resolution: %d x %d"\
							" | Change resolution with - / + keys"\
							"\n", screen_width(), screen_height());
}
