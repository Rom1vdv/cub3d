/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:37:16 by romvan-d          #+#    #+#             */
/*   Updated: 2023/06/23 15:09:38 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	instantiate_ray(t_cube *cube, int *x)
{
	int	x_coord;

	x_coord = *x;
	cube->camera.current_x = 2 * x_coord / (double)SCREEN_WIDTH - 1;
	cube->ray.direction_x = cube->player.director_vector_x + cube->camera.plane_x
		* cube->camera.current_x;
    printf("IN instantiate: ray->direction_x = %f\n", cube->ray.direction_x);
	printf("IN instantiate: player->director_vector_x = %f\n", cube->player.director_vector_x);
	cube->ray.direction_y = cube->player.director_vector_y + cube->camera.plane_y
		* cube->camera.current_x;
	cube->player.current_square_x = cube->map.player_x;
	cube->player.current_square_y = cube->map.player_y;
	printf("current_square_x = %d\n", cube->player.current_square_x);
	printf("current_square_y = %d\n", cube->player.current_square_y);
}

void	calculate_length_to_next_x(t_cube *cube)
{
	if (cube->ray.direction_x == 0)
		cube->ray.distance_to_next_x = 1e30;
	else
	{
		cube->ray.distance_to_next_x = fabs(1 / cube->ray.direction_x);
        //printf("distance_to_next_x = %f\n", ray->distance_to_next_x);
	}
	if (cube->ray.direction_y == 0)
		cube->ray.distance_to_next_y = 1e30;
	else
		cube->ray.distance_to_next_y = fabs(1 / cube->ray.direction_y);
}

void	calculate_step_and_side_dist(t_cube *cube)
{
	if (cube->ray.direction_x < 0)
	{
		cube->ray.step_in_x = -1;
		cube->ray.move_to_next_x = (cube->map.player_x
				- cube->player.current_square_x) * cube->ray.distance_to_next_x;
	}
	else
	{
		cube->ray.step_in_x = 1;
		cube->ray.move_to_next_x = (cube->player.current_square_x + 1.0
				- cube->map.player_x) * cube->ray.distance_to_next_x;
	}
	if (cube->ray.direction_y < 0)
	{
		cube->ray.step_in_y = -1;
		cube->ray.move_to_next_y = (cube->map.player_y
				- cube->player.current_square_y) * cube->ray.distance_to_next_y;
	}
	else
	{
		cube->ray.step_in_y = 1;
		cube->ray.move_to_next_y = (cube->player.current_square_y + 1.0
				- cube->map.player_y) * cube->ray.distance_to_next_y;
	}
}
void	perform_DDA_algorithm(t_cube *cube)
{
	cube->wall.is_hit = false;
	while (cube->wall.is_hit == false)
	{
		if (cube->ray.move_to_next_x < cube->ray.move_to_next_y)
		{
			cube->ray.move_to_next_x += cube->ray.distance_to_next_x;
			cube->player.current_square_x += cube->ray.step_in_x;
			cube->wall.which_side_hit = EAST_WEST;
		}
		else
		{
			cube->ray.move_to_next_y += cube->ray.distance_to_next_y;
			cube->player.current_square_y += cube->ray.step_in_y;
			cube->wall.which_side_hit = NORTH_SOUTH;
		}
		if (cube->map.map[cube->player.current_square_x][cube->player.current_square_y] == '1')
		{
			cube->wall.is_hit = true;
		}
	}
}

void	raycasting(t_cube *cube)
{
	int			x_coord;

	x_coord = 0;
	while (x_coord < SCREEN_WIDTH)
	{
        printf("RAYCASTING COORD: %d\n", x_coord);
		//change camera depending on NSEW -> modifying dirX and planeY together or dirY and planeX together
		instantiate_ray(cube, &x_coord);
		calculate_length_to_next_x(cube);
		calculate_step_and_side_dist(cube);
		perform_DDA_algorithm(cube);
		calculate_closest_point_to_wall(cube);
		calculate_height_line(cube);
		draw_column(cube, &x_coord);
		++x_coord;
	}
}
