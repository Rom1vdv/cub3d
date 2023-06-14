/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handling.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:06:07 by aburnott          #+#    #+#             */
/*   Updated: 2023/06/14 16:09:13 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_INIT_H
# define MLX_INIT_H
# include "raycasting.h"

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_DESTROY = 17
};

enum
{
	KEY_A = 0,
	KEY_D = 2,
	KEY_S = 1,
	KEY_W = 13,
	KEY_ESC = 53,
	KEY_RIGHT = 124,
	KEY_LEFT = 123,
};

int		init_mlx(t_mlx *mlx, t_cube *cube);
int		run_mlx(t_mlx *mlx, t_cube *cube);
int		key_pressed(int keycode, t_mlx *mlx);
int		ft_close(t_mlx *mlx);
int		ft_released(int keycode, t_mlx *mlx);
void	my_mlx_put_pixel(t_mlx *data, int x, int y, int color);
#endif