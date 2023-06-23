/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:26:09 by romvan-d          #+#    #+#             */
/*   Updated: 2023/06/23 14:51:47 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	movements(t_cube *cube)
{
	int	new_pos_y = 0;
	int	new_pos_x = 0;

	new_pos_x = (int)((double)(cube->map.player_x + 1.0 /* cube->player.director_vector_x */ * MOV_SPEED));
	new_pos_y = (int)((double)(cube->map.player_y + 0.0 /* cube->player.director_vector_y */ * MOV_SPEED));
    printf("START VAL: %f\n", cube->player.starting_pos_x);
	printf("pos x : %f\n", cube->map.player_x);
	printf("pos y : %f\n", cube->map.player_y);
	printf("new pos x : %d\n", new_pos_x);
	printf("mew pos y : %d\n", new_pos_y);
	printf("dir X : %f\n", cube->player.director_vector_x);
	printf("dir Y : %f\n", cube->player.director_vector_y);
	
	if (cube->map.map[new_pos_x][(int)cube->map.player_y] == '0')
	{
		printf("CALL LINE 28 IN CONTROLS\n");
		cube->player.starting_pos_x += cube->player.director_vector_x * MOV_SPEED;
	}
	if (cube->map.map[(int)(cube->map.player_x)][new_pos_y] == '0')
	{
		printf("CALL LINE 33 IN CONTROLS\n");
		cube->player.starting_pos_y += cube->player.director_vector_y * MOV_SPEED;
	}
}
