/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handling.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:06:07 by aburnott          #+#    #+#             */
/*   Updated: 2023/06/16 13:30:28 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_INIT_H
# define MLX_INIT_H
# include "cub3d.h"

int	    init_mlx(t_mlx *mlx, t_cube *cube);
int		run_mlx(t_mlx *mlx,t_cube *cube);
int		key_pressed(int keycode, t_mlx *mlx);
int		ft_close(t_mlx *mlx);
int		ft_released(int keycode, t_mlx *mlx);
void	my_mlx_put_pixel(t_mlx *data, int x, int y, int color);
#endif