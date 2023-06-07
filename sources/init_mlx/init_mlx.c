/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:11:55 by aburnott          #+#    #+#             */
/*   Updated: 2023/06/07 16:38:30 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	run_mlx(t_mlx *mlx)
{
	mlx_hook(mlx->win, ON_DESTROY, 0, ft_close, mlx);
	mlx_hook(mlx->win, ON_KEYDOWN, 0, key_pressed, mlx);
	mlx_hook(mlx->win, ON_KEYUP, 0, ft_released, mlx);
	mlx_loop(mlx->init);
	return (1);
}

int	init_mlx(t_mlx *mlx)
{	
	int	endian;
	int	bits_per_pixel;
	int	line_lenght;

	mlx->init = mlx_init();
	if (!mlx->init)
		return (0);
	mlx->win = mlx_new_window(mlx->init, WIDTH, HEIGHT, "cub3d");
	if (!mlx->win)
		return (0);
	mlx->img = mlx_new_image(mlx->init, WIDTH, HEIGHT);
	if (!mlx->img)
		return (0);
	mlx->addr = mlx_get_data_addr(mlx->img, &bits_per_pixel, &line_lenght,
			&endian);
	return (run_mlx(mlx));
}
