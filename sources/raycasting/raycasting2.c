/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:49:16 by romvan-d          #+#    #+#             */
/*   Updated: 2023/08/23 16:32:26 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_closest_point_to_wall(t_wall *wall, t_ray *ray)
{
	if (wall->which_side_hit == EAST_WEST)
		wall->shortest_dist_to_wall = (ray->move_to_next_x - ray->direction_x);
	else
		wall->shortest_dist_to_wall = (ray->move_to_next_y - ray->direction_y);
}

void	calculate_height_line(t_wall *wall, t_draw *draw)
{
	draw->line_height = (int)(SCREEN_HEIGHT / wall->shortest_dist_to_wall);
	draw->start_pos = -draw->line_height / 2 + SCREEN_HEIGHT / 2;
	if (draw->start_pos < 0)
		draw->start_pos = 0;
	draw->end_pos = draw->line_height / 2 + SCREEN_HEIGHT / 2;
	if (draw->end_pos >= SCREEN_HEIGHT)
		draw->end_pos = SCREEN_HEIGHT - 1;
}

void	draw_column(t_wall *wall, t_map *map, t_mlx *mlx, int *x, t_draw *draw)
{
	int	y;

	(void) wall;
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		if (y < draw->start_pos)
		{
			my_mlx_put_pixel(mlx, *x, y, map->ceiling);
		}
		else if (y > draw->end_pos)
		{
			my_mlx_put_pixel(mlx, *x, y, map->floor);
		}
		else
		{
			if (wall->which_side_hit == NORTH_SOUTH)
			{
				my_mlx_put_pixel(mlx, *x, y, 0x00FF00);
			}
			my_mlx_put_pixel(mlx, *x, y, 0x0000FF);
		}
		++y;
	}
}
void	draw_columns(t_ray *ray, t_textures *textures, t_wall *wall, t_map *map, t_draw *draw)
{
	int	y;
	
	y = 0;
	if (wall->which_side_hit == NORTH_SOUTH)
	{
		textures->wall_x = map->player_y + wall->shortest_dist_to_wall * ray->direction_y;
	}
	else
		textures->wall_x = map->player_x + wall->shortest_dist_to_wall * ray->direction_x;
	textures->wall_x -= floor(textures->wall_x);
	textures->x = (int)(textures->wall_x * textures->width);
	if (wall->which_side_hit == NORTH_SOUTH && ray->direction_y < 0)
		textures->x = textures->width - textures->x - 1;
	if (wall->which_side_hit == EAST_WEST && ray->direction_x > 0)
		textures->x = textures->width - textures->x - 1;
	y += fill_wall_texture(draw, ray, textures, y);
}

