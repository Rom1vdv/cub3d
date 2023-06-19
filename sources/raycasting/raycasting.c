/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:37:16 by romvan-d          #+#    #+#             */
/*   Updated: 2023/06/19 14:56:47 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	instantiate_ray(t_camera *camera, t_ray *ray, t_player *player, int *x, t_map *map)
{
	int	x_coord;

	x_coord = *x;
	camera->current_x = 2 * x_coord / (double)SCREEN_WIDTH - 1;
	ray->direction_x = player->director_vector_x + camera->plane_x
		* camera->current_x;
	ray->direction_y = player->director_vector_y + camera->plane_y
		* camera->current_x;
	player->current_square_x = map->player_x;
	player->current_square_y = map->player_y;
}

void	calculate_length_to_next_x(t_ray *ray)
{
	if (ray->direction_x == 0)
		ray->distance_to_next_x = 1e30;
	else
		ray->distance_to_next_x = fabs(1 / ray->direction_x);
	if (ray->direction_y == 0)
		ray->distance_to_next_y = 1e30;
	else
		ray->distance_to_next_y = fabs(1 / ray->direction_y);
}

void	calculate_step_and_side_dist(t_player *player, t_ray *ray, t_map *map)
{
	if (ray->direction_x < 0)
	{
		ray->step_in_x = -1;
		ray->move_to_next_x = (map->player_x
				- player->current_square_x) * ray->distance_to_next_x;
	}
	else
	{
		ray->step_in_x = 1;
		ray->move_to_next_x = (player->current_square_x + 1.0
				- map->player_x) * ray->distance_to_next_x;
	}
	if (ray->direction_y < 0)
	{
		ray->step_in_y = -1;
		ray->move_to_next_y = (map->player_y
				- player->current_square_y) * ray->distance_to_next_y;
	}
	else
	{
		ray->step_in_y = 1;
		ray->move_to_next_y = (player->current_square_y + 1.0
				- map->player_y) * ray->distance_to_next_y;
	}
}
void	perform_DDA_algorithm(t_ray *ray, t_player *player, t_wall *wall, t_map *map)
{
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
			ray->move_to_next_y += ray->distance_to_next_y;
			player->current_square_y += ray->step_in_y;
			wall->which_side_hit = NORTH_SOUTH;
		}
		if (map->map[player->current_square_x][player->current_square_y] == '1')
		{
			wall->is_hit = true;
		}
	}
}

void	raycasting(t_cube *cube)
{
	int			x_coord;

	x_coord = 0;
	printf("%d", cube->map.player_x);
	printf("%d", cube->map.player_y);
	while (x_coord < SCREEN_WIDTH)
	{
		instantiate_ray(&cube->camera, &cube->ray, &cube->player, &x_coord, &cube->map);
		calculate_length_to_next_x(&cube->ray);
		calculate_step_and_side_dist(&cube->player, &cube->ray, &cube->map);
		perform_DDA_algorithm(&cube->ray, &cube->player, &cube->wall, &cube->map);
		calculate_closest_point_to_wall(&cube->wall, &cube->ray);
		calculate_height_line(&cube->wall, &cube->draw);
		draw_column(&cube->wall, &cube->map, &cube->mlx, &x_coord, &cube->draw);
		++x_coord;
	}
}
