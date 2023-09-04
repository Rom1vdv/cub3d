/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:46:32 by romvan-d          #+#    #+#             */
/*   Updated: 2023/09/04 13:30:59 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// static void	put_square(t_mlx *mlx, int x, int y, unsigned int color, int width)
// {
// 	for (int deltax = 0; deltax < width; deltax++)
// 	{
// 		for (int deltay = 0; deltay < width; deltay++)
// 		my_mlx_put_pixel(mlx, x * width + deltax, y * width + deltay, color);
// 	}
// }

// static	void display_wall(t_cube *cube)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while(cube->map.map[y] && y < 5)
// 	{
// 		x = 0;
// 		while(cube->map.map[y][x])
// 		{
// 			if (cube->map.map[y][x] == '1')
// 				put_square(&cube->mlx, x, y, 0x00FF00, 3);
// 			++x;
// 		}
// 		++y;
// 	}
// }

// static void	display_minimap(t_cube *cube)
// {
// 	int x;
// 	int y;
	
// 	x = 0;
// 	while(x < 50)
// 	{
// 		y = 0;
// 		while (y < 30)
// 		{
// 			my_mlx_put_pixel(&cube->mlx, x, y, 0);
// 			++y;
// 		}
// 		++x;
// 	}
// 	put_square(&cube->mlx, (int)cube->map.player_x, (int)cube->map.player_y, 0xFF0000, 5);
// 	mlx_put_image_to_window(cube->mlx.init, cube->mlx.win, cube->mlx.img, 0, 0);
// }

int	cube_loop(t_cube *cube)
{
	render(cube);
	// display_wall(cube);
	// display_minimap(cube);
	return (0);
}
