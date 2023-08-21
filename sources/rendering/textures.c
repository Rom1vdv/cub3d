/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:27:23 by romvan-d          #+#    #+#             */
/*   Updated: 2023/08/21 12:54:16 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	color_floor_ceiling(t_draw *draw, t_map *map, t_mlx *mlx, int y, int x)
{
	if (draw->end_pos)
	{
		draw->end_pos = SCREEN_HEIGHT;
	}
	y = draw->end_pos;
	while (y < SCREEN_HEIGHT)
	{
		my_mlx_put_pixel(mlx, x, y, map->floor);
		my_mlx_put_pixel(mlx, x, SCREEN_HEIGHT - y - 1, map->ceiling);
		++y;
	}
}

void	fill_wall_texture(t_draw *draw, t_ray *ray, t_textures *textures, int y)
{
	y = draw->start_pos;
	while(y < draw->end_pos)
	{
		textures->texture_y = (int)(y * 2 - SCREEN_HEIGHT + draw->line_height)
			* (TEXTURE_HEIGHT / 2) / draw->line_height;
		++y;
	}
}