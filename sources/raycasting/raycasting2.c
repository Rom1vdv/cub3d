/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:49:16 by romvan-d          #+#    #+#             */
/*   Updated: 2023/06/16 16:36:45 by aburnott         ###   ########.fr       */
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
void	calculate_height_line(t_wall *wall, t_draw *draw, t_map *map)
{
	draw->line_height = (float)(map->y / wall->shortest_dist_to_wall);
	draw->start_pos = - draw->line_height / 2 + map->y / 2;
	if (draw->start_pos < 0)
		draw->start_pos = 0;
	draw->end_pos = draw->line_height / 2 + map->y / 2;
	if (draw->end_pos >= map->y)
		draw->end_pos = map->y - 1;
}
void	draw_column(t_wall *wall, t_map *map, t_mlx *mlx, int *x, t_draw *draw)
{
	int	y;

	y = 0;
	printf("%f\n", wall->shortest_dist_to_wall);
	while (y < map->y)
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
