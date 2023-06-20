/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:26:09 by romvan-d          #+#    #+#             */
/*   Updated: 2023/06/20 10:47:36 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	movements(t_cube *cube)
{
	int	new_pos_y = 0;
	int	new_pos_x = 0;

	printf("cube->player.starting_pos_x : %f\n", cube->player.starting_pos_x);
	printf("cube->player.director_vector_x : %f\n", cube->player.director_vector_x);
	new_pos_x = cube->player.starting_pos_x + cube->player.director_vector_x * MOV_SPEED;
	printf("cube->player.starting_pos_y : %f\n", cube->player.starting_pos_y);
	printf("cube->player.director_vector_y : %f\n", cube->player.director_vector_y);
	new_pos_y = cube->player.starting_pos_y + cube->player.director_vector_y * MOV_SPEED;
	printf("new_pos x : %d\n", new_pos_x);
	printf("new_pos y : %d\n", new_pos_y);
	printf("current square y : %d\n", cube->player.current_square_y);
	if (cube->map.map[new_pos_x][(int)cube->player.current_square_y] == 0)
	{
		printf("CALL LINE 28 IN CONTROLS\n");
		cube->player.starting_pos_x += cube->player.director_vector_x * MOV_SPEED;
	}
	if (cube->map.map[(int)(cube->player.starting_pos_x)][new_pos_y] == 0)
	{
		printf("CALL LINE 33 IN CONTROLS\n");
		cube->player.starting_pos_y += cube->player.director_vector_y * MOV_SPEED;
	}
}
