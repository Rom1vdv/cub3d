/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:05:41 by romvan-d          #+#    #+#             */
/*   Updated: 2023/06/26 16:17:19 by romvan-d         ###   ########.fr       */
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
		movements(cube);
	else if (keycode == KEY_S)
		printf("S PRESSED\n");
	else if (keycode == KEY_A)
		printf("A PRESSED\n");
	else if (keycode == KEY_D)
		printf("D PRESSED\n");
	else if (keycode == KEY_LEFT)
		printf("LEFT PRESSED\n");
	else if (keycode == KEY_RIGHT)
		printf("RIGHT PRESSED\n");
	return (0);
}

int	ft_released(int keycode, t_mlx *mlx)
{
	(void) keycode;
	(void) *mlx;
	return (0);
}

int	to_xpm(t_mlx *mlx, t_cube *cube)
{
	//NEED TO CHECK MLX RETURN AND VALIDITY
	cube->xpm_file.wall_ea = mlx_xpm_file_to_image(mlx->init, cube->textures.ea,
			&cube->xpm_file.width, &cube->xpm_file.height);
	cube->xpm_file.wall_no = mlx_xpm_file_to_image(mlx->init, cube->textures.no,
			&cube->xpm_file.width, &cube->xpm_file.height);
	cube->xpm_file.wall_so = mlx_xpm_file_to_image(mlx->init, cube->textures.so,
			&cube->xpm_file.width, &cube->xpm_file.height);
	cube->xpm_file.wall_we = mlx_xpm_file_to_image(mlx->init, cube->textures.we,
			&cube->xpm_file.width, &cube->xpm_file.height);
	return (0);
}