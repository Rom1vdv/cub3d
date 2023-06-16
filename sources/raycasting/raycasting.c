/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:37:16 by romvan-d          #+#    #+#             */
/*   Updated: 2023/06/16 14:08:11 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	instantiate_ray(t_camera *camera, t_ray *ray, t_player *player, int *x)
{
	int	x_coord;

	x_coord = *x;
	camera->current_x = (2 * x_coord / (double)SCREEN_WIDTH) - 1;
	ray->direction_x = player->director_vector_x + camera->plane_x
		* camera->current_x;
	ray->direction_y = player->director_vector_y + camera->plane_y
		* camera->current_x;
}

void	calculate_length_to_next_x(t_ray *ray)
{
	if (ray->direction_x == 0)
		ray->direction_x = __INT_MAX__;
	else
		ray->distance_to_next_x = (1 / ray->direction_x);
	if (ray->direction_y == 0)
		ray->direction_y = __INT_MAX__;
	else
		ray->distance_to_next_y = (1 / ray->direction_y);
}

void	calculate_step_and_side_dist(t_player *player, t_ray *ray)
{
	if (ray->direction_x < 0)
	{
		ray->step_in_x = -1;
		ray->move_to_next_x = (player->starting_pos_x
				- player->current_square_x) * ray->distance_to_next_x;
	}
	else
	{
		ray->step_in_x = 1;
		ray->move_to_next_x = (player->current_square_x + 1.0
				- player->starting_pos_x) * ray->distance_to_next_x;
	}
	if (ray->direction_y < 0)
	{
		ray->step_in_y = -1;
		ray->move_to_next_y = (player->starting_pos_y
				- player->current_square_y) * ray->distance_to_next_y;
	}
	else
	{
		ray->step_in_y = 1;
		ray->move_to_next_y = (player->current_square_y + 1.0
				- player->starting_pos_y) * ray->distance_to_next_y;
	}
}
void	perform_DDA_algorithm(t_ray *ray, t_player *player, t_wall *wall, t_map *map)
{
	wall->is_hit = false;
	while (wall->is_hit == false)
	{
		if (ray->move_to_next_x < ray->move_to_next_y)
		{
			ray->move_to_next_x += ray->distance_to_next_x;
			player->current_square_x += ray->step_in_x;
			wall->which_side_hit = EAST_WEST;
		}
		else
		{
			ray->move_to_next_x += ray->distance_to_next_y;
			player->current_square_y += ray->step_in_y;
			wall->which_side_hit = NORTH_SOUTH;
		}
		if (map->map[player->current_square_x][player->current_square_y] == 1)
			wall->is_hit = true;
	}
}

void	raycasting(t_cube *cube)
{
	int			x_coord;

	x_coord = 0;
	cube->player.current_square_x = cube->map.player_x;
	cube->player.current_square_y = cube->map.player_y;
	while (x_coord < SCREEN_WIDTH)
	{
		instantiate_ray(&cube->camera, &cube->ray, &cube->player, &x_coord);
		calculate_length_to_next_x(&cube->ray);
		calculate_step_and_side_dist(&cube->player, &cube->ray);
		perform_DDA_algorithm(&cube->ray, &cube->player, &cube->wall, &cube->map);
		calculate_closest_point_to_wall(&cube->wall, &cube->ray);
		calculate_height_line(&cube->wall, &cube->draw);
		draw_column(&cube->wall, &cube->draw, &cube->mlx, &x_coord);
		++x_coord;
	}
}
