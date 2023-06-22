/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:54:56 by romvan-d          #+#    #+#             */
/*   Updated: 2023/06/20 13:58:43 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render(t_cube *cube)
{
	raycasting(cube);
	mlx_put_image_to_window(&cube->mlx, cube->mlx.win, cube->mlx.img, 0, 0);
}