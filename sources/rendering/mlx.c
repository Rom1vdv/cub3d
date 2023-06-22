/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 02:29:09 by rom1              #+#    #+#             */
/*   Updated: 2023/06/22 16:34:07 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_put_pixel(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = data->address + (y * data->line_length + x
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
int	run_mlx(t_mlx *mlx, t_cube *cube)
{
	mlx_hook(mlx->win, ON_DESTROY, 0, ft_close, mlx);
	mlx_hook(mlx->win, ON_KEYUP, 0, ft_released, mlx);
	mlx_hook(mlx->win, ON_KEYDOWN, 0, key_pressed, mlx);
	raycasting(cube);
	render(cube);
	mlx_put_image_to_window(mlx, mlx->win, mlx->img, 0, 0);
	mlx_loop(mlx->init);
	return (1);
}
