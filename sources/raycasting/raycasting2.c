/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:49:16 by romvan-d          #+#    #+#             */
/*   Updated: 2023/06/18 21:48:17 by aburnott         ###   ########.fr       */
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
	draw->start_pos = - draw->line_height / 2 + SCREEN_HEIGHT / 2;
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
			my_mlx_put_pixel(mlx, *x, y, 0x000000);
		}
		++y;
	}
}
