/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:05:41 by romvan-d          #+#    #+#             */
/*   Updated: 2023/09/13 13:26:54 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close(t_mlx *mlx, t_cube *cube)
{
	if (mlx->win)
		mlx_destroy_window(mlx->init, mlx->win);
	if (mlx->img)
		mlx_destroy_image(mlx->init, mlx->img);
	if (cube->map.map)
		ft_free_end(cube);
	exit(1);
	return (0);
}

int	key_pressed(int keycode, t_cube *cube)
{
	if (keycode == KEY_ESC)
		ft_close(&cube->mlx, cube);
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

static void	check_size(int *width, int *height)
{
	if (*width != 64)
		error(0, "Invalid texture width\n", 0);
	if (*height != 64)
		error(0, "Invalid texture height\n", 0);
}

void	to_xpm(t_mlx *mlx, t_cube *cube)
{
	int	x;
	int	y;
	int	z;

	cube->textures.wall_ea = mlx_xpm_file_to_image(mlx->init, cube->textures.ea,
			&cube->textures.width, &cube->textures.height);
	check_size(&cube->textures.width, &cube->textures.height);
	cube->textures.wall_no = mlx_xpm_file_to_image(mlx->init, cube->textures.no,
			&cube->textures.width, &cube->textures.height);
	check_size(&cube->textures.width, &cube->textures.height);
	cube->textures.wall_so = mlx_xpm_file_to_image(mlx->init, cube->textures.so,
			&cube->textures.width, &cube->textures.height);
	check_size(&cube->textures.width, &cube->textures.height);
	cube->textures.wall_we = mlx_xpm_file_to_image(mlx->init, cube->textures.we,
			&cube->textures.width, &cube->textures.height);
	check_size(&cube->textures.width, &cube->textures.height);
	cube->textures.stored[0] = mlx_get_data_addr(cube->textures.wall_no,
			&x, &y, &z);
	cube->textures.stored[1] = mlx_get_data_addr(cube->textures.wall_so,
			&x, &y, &z);
	cube->textures.stored[2] = mlx_get_data_addr(cube->textures.wall_ea,
			&x, &y, &z);
	cube->textures.stored[3] = mlx_get_data_addr(cube->textures.wall_we,
			&x, &y, &z);
}
