/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:21:41 by aburnott          #+#    #+#             */
/*   Updated: 2023/06/02 22:15:53 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_close(t_mlx *mlx)
{
	if (mlx->win)
		mlx_destroy_window(mlx->init, mlx->win);
	if (mlx->img)
		mlx_destroy_image(mlx->init, mlx->img);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_pressed(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		ft_close(mlx);
	else if (keycode == KEY_W)
		printf("W PRESSED\n");
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

int	to_xpm(t_mlx *mlx, t_cub *cub)
{
	//NEED TO CHECK MLX RETURN AND VALIDITY
	cub->xpm_file.wall_ea = mlx_xpm_file_to_image(mlx->init, cub->textures.ea,
			&cub->xpm_file.width, &cub->xpm_file.height);
	cub->xpm_file.wall_no = mlx_xpm_file_to_image(mlx->init, cub->textures.no,
			&cub->xpm_file.width, &cub->xpm_file.height);
	cub->xpm_file.wall_so = mlx_xpm_file_to_image(mlx->init, cub->textures.so,
			&cub->xpm_file.width, &cub->xpm_file.height);
	cub->xpm_file.wall_we = mlx_xpm_file_to_image(mlx->init, cub->textures.we,
			&cub->xpm_file.width, &cub->xpm_file.height);
	return (0);
}
