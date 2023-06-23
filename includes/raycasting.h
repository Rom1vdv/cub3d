/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:32:55 by romvan-d          #+#    #+#             */
/*   Updated: 2023/06/23 14:09:29 by aburnott         ###   ########.fr       */
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
void	calculate_closest_point_to_wall(t_cube *cube);
void	calculate_height_line(t_cube *cube);
void	draw_column(t_cube *cube, int *x);


#endif