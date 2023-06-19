/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:26:09 by romvan-d          #+#    #+#             */
/*   Updated: 2023/06/19 16:48:26 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	movements(t_cube *cube)
{
	if (cube->map.map[(int)(cube->player.starting_pos_x + cube->player.director_vector_x * MOV_SPEED)][(int)cube->player.current_square_y] == 0)
	{
		cube->player.starting_pos_x += cube->player.director_vector_x * MOV_SPEED;
	}
	if (cube->map.map[(int)(cube->player.starting_pos_x)][(int)(cube->player.current_square_y + cube->player.director_vector_y * MOV_SPEED)] == 0)
	{
		cube->player.starting_pos_y += cube->player.director_vector_y * MOV_SPEED;
	}
}