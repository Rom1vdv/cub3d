/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:26:09 by romvan-d          #+#    #+#             */
/*   Updated: 2023/09/22 14:27:17 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	forward_movement(t_cube *cube)
{
	int	new_pos_x;
	int	new_pos_y;

	new_pos_x = cube->map.player_x + (cube->player.director_vector_x + 0.01)
		* MOV_SPEED;
	new_pos_y = cube->map.player_y + (cube->player.director_vector_y + 0.01) 
		* MOV_SPEED;
	if (cube->map.map[new_pos_x][(int)cube->map.player_y] != '1')
	{
		cube->map.player_x += cube->player.director_vector_x * MOV_SPEED;
	}
	if (cube->map.map[(int)(cube->map.player_x)][new_pos_y] != '1')
	{
		cube->map.player_y += cube->player.director_vector_y * MOV_SPEED;
	}
}

void	backward_movement(t_cube *cube)
{
	int	new_pos_x;
	int	new_pos_y;

	new_pos_x = cube->map.player_x - (cube->player.director_vector_x + 0.01)
		* MOV_SPEED;
	new_pos_y = cube->map.player_y - (cube->player.director_vector_y + 0.01) 
		* MOV_SPEED;
	if (cube->map.map[new_pos_x][(int)cube->map.player_y] != '1')
	{
		cube->map.player_x -= cube->player.director_vector_x * MOV_SPEED;
	}
	if (cube->map.map[(int)(cube->map.player_x)][new_pos_y] != '1')
	{
		cube->map.player_y -= cube->player.director_vector_y * MOV_SPEED;
	}
}

void	left_movement(t_cube *cube)
{
	int	new_pos_x;
	int	new_pos_y;

	new_pos_x = cube->map.player_x - (cube->camera.plane_x + 0.01) * MOV_SPEED;
	new_pos_y = cube->map.player_y - (cube->camera.plane_y + 0.01) * MOV_SPEED;
	if (cube->map.map[new_pos_x][(int)cube->map.player_y] != '1')
	{
		cube->map.player_x -= cube->camera.plane_x * MOV_SPEED;
	}
	if (cube->map.map[(int)cube->map.player_x][new_pos_y] != '1')
	{
		cube->map.player_y -= cube->camera.plane_y * MOV_SPEED;
	}
}

void	right_movement(t_cube *cube)
{
	int	new_pos_x;
	int	new_pos_y;

	new_pos_x = cube->map.player_x + (cube->camera.plane_x + 0.01) * MOV_SPEED;
	new_pos_y = cube->map.player_y + (cube->camera.plane_y + 0.01) * MOV_SPEED;
	if (cube->map.map[new_pos_x][(int)cube->map.player_y] != '1')
	{
		printf(" first player x :%d \n", cube->player.current_square_x);
		printf(" map player x :%f \n", cube->map.player_x);
		printf("x position player y :%d \n", cube->player.current_square_y);
		cube->map.player_x += cube->camera.plane_x * MOV_SPEED;
	}
	if (cube->map.map[(int)cube->map.player_x][new_pos_y] != '1')
	{
		printf("y position player x :%d \n", cube->player.current_square_x);
		printf("y position player y :%d \n", cube->player.current_square_y);
		cube->map.player_y += cube->camera.plane_y * MOV_SPEED;
	}
}
