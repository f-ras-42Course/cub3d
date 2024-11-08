/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_graphics.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 18:14:12 by fras          #+#    #+#                 */
/*   Updated: 2024/11/08 18:14:13 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_GRAPHICS_H
# define TEST_GRAPHICS_H

# include "graphics.h"

// - Raycasting
//-Textured
void		test_texture(mlx_image_t *image, const mlx_texture_t *texture);

// -- Single Raycasting (for testing)
void		single_raycasting_textured(t_mainlayer *mainlayer);
void		single_raycasting(t_mainlayer *mainlayer, uint32_t ceiling_color, \
								uint32_t floor_color);
void		single_place_ceiling(mlx_image_t *image, int wall_height, \
									int position, uint32_t color);
void		single_place_wall(mlx_image_t *image, int wall_height, \
								int position, uint32_t color);
void		single_place_floor(mlx_image_t *image, int wall_height, \
								int position, uint32_t color);

// - Minimap framworks (for testing)
void		draw_minimap_frame(const t_minimap *minimap, \
								t_minimap_options option);

// -- Single line bigmap (for testing)
void		bigmap_single_ray(const t_bigmap *bigmap);
void		bigmap_draw_direction_angle(const t_bigmap *bigmap, int color);
void		draw_bigmap_raster(const t_bigmap *bigmap);

#endif