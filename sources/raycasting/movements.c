/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:26:09 by romvan-d          #+#    #+#             */
/*   Updated: 2023/08/07 16:34:51 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	forward_movement(t_cube *cube)
{
	int	new_pos_x;
	int	new_pos_y;

	printf("dir X : %f\n", cube->player.director_vector_x);
	printf("dir Y : %f\n", cube->player.director_vector_y);
	new_pos_x = cube->map.player_x + cube->player.director_vector_x * MOV_SPEED;
	new_pos_y = cube->map.player_y + cube->player.director_vector_y * MOV_SPEED;
	printf("pos x : %f\n", cube->map.player_x);
	printf("pos y : %f\n", cube->map.player_y);
	printf("new pos x : %d\n", new_pos_x);
	printf("mew pos y : %d\n", new_pos_y);
	if (cube->map.map[(int)cube->map.player_y][new_pos_x] != '1')
	{
		printf("nsm\n");
		cube->map.player_x += cube->player.director_vector_x * MOV_SPEED;
	}
	if (cube->map.map[new_pos_y][(int)(cube->map.player_x)] != '1')
	{
		cube->map.player_y += cube->player.director_vector_y * MOV_SPEED;
	}
}

void	backward_movement(t_cube *cube)
{
	int	new_pos_x;
	int	new_pos_y;

	new_pos_x = cube->map.player_x - cube->player.director_vector_x * MOV_SPEED;
	new_pos_y = cube->map.player_y - cube->player.director_vector_y * MOV_SPEED;
	if (cube->map.map[(int)cube->map.player_y][new_pos_x] != '1')
	{
		cube->map.player_x -= cube->player.director_vector_x * MOV_SPEED;
	}
	if (cube->map.map[new_pos_y][(int)(cube->map.player_x)] != '1')
	{
		cube->map.player_y -= cube->player.director_vector_y * MOV_SPEED;
	}
}

void	left_movement(t_cube *cube)
{
	int	new_pos_x;
	int	new_pos_y;

	new_pos_x = cube->map.player_x - cube->camera.plane_x * MOV_SPEED;
	new_pos_y = cube->map.player_y - cube->camera.plane_y * MOV_SPEED;
	if (cube->map.map[new_pos_x][(int)cube->map.player_y] != '1')
		cube->map.player_x -= cube->camera.plane_x * MOV_SPEED;
	if (cube->map.map[(int)cube->map.player_x][new_pos_y] != '1')
		cube->map.player_y -= cube->camera.plane_y * MOV_SPEED;
}

void	right_movement(t_cube *cube)
{
	int	new_pos_x;
	int	new_pos_y;

	new_pos_x = cube->map.player_x + cube->camera.plane_x * MOV_SPEED;
	new_pos_y = cube->map.player_y + cube->camera.plane_y * MOV_SPEED;
	if (cube->map.map[new_pos_x][(int)cube->map.player_y] != '1')
		cube->map.player_x += cube->camera.plane_x * MOV_SPEED;
	if (cube->map.map[(int)cube->map.player_x][new_pos_y] != '1')
		cube->map.player_y += cube->camera.plane_y * MOV_SPEED;
}
