/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:26:09 by romvan-d          #+#    #+#             */
/*   Updated: 2023/06/19 17:12:12 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	movements(t_cube *cube)
{
	int	new_pos_x;
	int	new_pos_y;

	new_pos_x = cube->player.starting_pos_x + cube->player.director_vector_x * MOV_SPEED;
	new_pos_y = cube->player.starting_pos_y + cube->player.director_vector_y * MOV_SPEED;
	printf("pos x : %d\n", new_pos_x);
	printf("pos y : %d\n", new_pos_y);
	if (cube->map.map[new_pos_x][(int)cube->player.current_square_y] == 0)
	{
		cube->player.starting_pos_x += cube->player.director_vector_x * MOV_SPEED;
	}
	if (cube->map.map[(int)(cube->player.starting_pos_x)][new_pos_y] == 0)
	{
		cube->player.starting_pos_y += cube->player.director_vector_y * MOV_SPEED;
	}
}
