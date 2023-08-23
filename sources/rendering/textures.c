/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:27:23 by romvan-d          #+#    #+#             */
/*   Updated: 2023/08/23 16:36:29 by romvan-d         ###   ########.fr       */
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

void	fill_wall_texture(t_draw *draw, t_ray *ray, t_textures *textures, t_wall *wall, int y)
{
	y = draw->start_pos;
	while(y < draw->end_pos)
	{
		textures->y = (int)(y * 2 - SCREEN_HEIGHT + draw->line_height)
			* (textures->height / 2) / draw->line_height;
		if (wall->which_side_hit == NORTH_SOUTH && ray->direction_y > 0)
			textures->choice = 0;
		if (wall->which_side_hit == NORTH_SOUTH && ray->direction_y < 0)
			textures->choice = 1;
		if (wall->which_side_hit == EAST_WEST && ray->direction_x > 0)
			textures->choice = 2;
		if (wall->which_side_hit == EAST_WEST && ray->direction_x < 0)
			textures->choice = 3;
		++y;
	}
}
