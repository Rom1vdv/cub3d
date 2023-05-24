/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:32:55 by romvan-d          #+#    #+#             */
/*   Updated: 2023/05/24 14:41:38 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H


typedef struct s_player
{
	double	starting_pos_x;
	double	starting_pos_y;
	double	director_vector_x;
	double	director_vector_y;
}	t_player;

typedef struct s_camera
{
	double	plane_x;
	double	plane_y;
	double	current_x;
}	t_camera;

typedef struct s_time
{
	double	current_time;
	double	previous_time;
}	t_time;

typedef struct s_ray
{
	int		current_square_x;
	int		current_square_y;
	double	
}	t_ray;

#endif