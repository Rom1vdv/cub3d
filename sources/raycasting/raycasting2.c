/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:49:16 by romvan-d          #+#    #+#             */
/*   Updated: 2023/08/15 19:55:16 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_closest_point_to_wall(t_cube *cube)
{
	if (cube->wall.which_side_hit == EAST_WEST)
		cube->wall.shortest_dist_to_wall = (cube->ray.move_to_next_x - cube->ray.direction_x);
	else
		cube->wall.shortest_dist_to_wall = (cube->ray.move_to_next_y - cube->ray.direction_y);
}
<<<<<<< HEAD
void	calculate_height_line(t_cube *cube)
{
	cube->draw.line_height = (int)(SCREEN_HEIGHT / cube->wall.shortest_dist_to_wall);
	cube->draw.start_pos = - cube->draw.line_height / 2 + SCREEN_HEIGHT / 2;
	if (cube->draw.start_pos < 0)
		cube->draw.start_pos = 0;
	cube->draw.end_pos = cube->draw.line_height / 2 + SCREEN_HEIGHT / 2;
	if (cube->draw.end_pos >= SCREEN_HEIGHT)
		cube->draw.end_pos = SCREEN_HEIGHT - 1;
}
void	draw_column(t_cube *cube, int *x)
=======

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
>>>>>>> romvan-d
{
	int	y;

	//(void) wall;
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		if (y < cube->draw.start_pos)
		{
			my_mlx_put_pixel(&cube->mlx, *x, y, cube->map.ceiling);
		}
		else if (y > cube->draw.end_pos)
		{
			my_mlx_put_pixel(&cube->mlx, *x, y, cube->map.floor);
		}
		else
		{
			if (cube->wall.which_side_hit == NORTH_SOUTH)
			{
				my_mlx_put_pixel(&cube->mlx, *x, y, 0x00FF00);
			}
			my_mlx_put_pixel(&cube->mlx, *x, y, 0x0000FF);
		}
		++y;
	}
}
