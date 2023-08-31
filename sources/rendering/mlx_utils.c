/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:05:41 by romvan-d          #+#    #+#             */
/*   Updated: 2023/08/31 13:12:45 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close(t_mlx *mlx)
{
	if (mlx->win)
		mlx_destroy_window(mlx->init, mlx->win);
	if (mlx->img)
		mlx_destroy_image(mlx->init, mlx->img);
	exit(1);
	return (0);
}

int	key_pressed(int keycode, t_cube *cube)
{
	if (keycode == KEY_ESC)
		ft_close(&cube->mlx);
	else if (keycode == KEY_W)
		forward_movement(cube);
	else if (keycode == KEY_S)
		backward_movement(cube);
	else if (keycode == KEY_A)
		left_movement(cube);
	else if (keycode == KEY_D)
		right_movement(cube);
	else if (keycode == KEY_LEFT)
		rotate_left(cube);
	else if (keycode == KEY_RIGHT)
		rotate_right(cube);
	return (0);
}

void	to_xpm(t_mlx *mlx, t_cube *cube)
{	
	int	i;
	int x;
	int y;
	int z;
	i = 0;
	cube->textures.wall_ea = mlx_xpm_file_to_image(mlx->init, cube->textures.ea,
			&cube->textures.width, &cube->textures.height);
	cube->textures.wall_no = mlx_xpm_file_to_image(mlx->init, cube->textures.no,
			&cube->textures.width, &cube->textures.height);
	cube->textures.wall_so = mlx_xpm_file_to_image(mlx->init, cube->textures.so,
			&cube->textures.width, &cube->textures.height);
	cube->textures.wall_we = mlx_xpm_file_to_image(mlx->init, cube->textures.we,
			&cube->textures.width, &cube->textures.height);
	cube->textures.stored[0] = mlx_get_data_addr(cube->textures.wall_no,
		&x, &y, &z);
	cube->textures.stored[1] = mlx_get_data_addr(cube->textures.wall_so,
		&x, &y, &z);
	cube->textures.stored[2] = mlx_get_data_addr(cube->textures.wall_ea,
		&x, &y, &z);
	cube->textures.stored[3] = mlx_get_data_addr(cube->textures.wall_we,
		&x, &y, &z);
}
