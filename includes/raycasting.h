/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:32:55 by romvan-d          #+#    #+#             */
/*   Updated: 2023/08/07 16:06:07 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

#include "cub3d.h"

# ifndef SCREEN_WIDTH
#  define SCREEN_WIDTH 640
# endif
# ifndef SCREEN_HEIGHT
#  define SCREEN_HEIGHT 480
# endif

# ifndef NORTH_SOUTH
# define NORTH_SOUTH 1
# endif
# ifndef EAST_WEST
# define EAST_WEST 0
# endif

# ifndef MOV_SPEED
# define MOV_SPEED 0.1
# endif
# ifndef ROT_SPEED
# define ROT_SPEED 0.01
# endif


void	raycasting(t_cube *cube);
void	calculate_closest_point_to_wall(t_wall *wall, t_ray *ray);
void	calculate_height_line(t_wall *wall, t_draw *draw);
void	draw_column(t_wall *wall, t_map *map, t_mlx *mlx, int *x, t_draw *draw);
void	init_camera_position(t_player *player, t_map *map, t_camera *camera);

#endif