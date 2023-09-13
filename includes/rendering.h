/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:06:07 by aburnott          #+#    #+#             */
/*   Updated: 2023/09/13 11:53:02 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include "cub3d.h"

int		init_mlx(t_mlx *mlx, t_cube *cube);
int		run_mlx(t_mlx *mlx, t_cube *cube);
int		key_pressed(int keycode, t_cube *cube);
int		ft_close(t_mlx *mlx, t_cube *cube);
int		ft_released(int keycode, t_cube *cube);
void	my_mlx_put_pixel(t_mlx *data, int x, int y, int color);
void	render(t_cube *cube);
int		cube_loop(t_cube *cube);
void	to_xpm(t_mlx *mlx, t_cube *cube);
#endif