/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rom1 <rom1@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:32:55 by romvan-d          #+#    #+#             */
/*   Updated: 2023/06/14 02:12:35 by rom1             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H
# include <math.h>
# include <stdbool.h>

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

typedef struct s_player
{
	double	starting_pos_x; //posX
	double	starting_pos_y; // posY
	double	director_vector_x; //dirX
	double	director_vector_y; //dirY
	int		current_square_x; //mapX
	int		current_square_y; //mapY
	
}	t_player;

typedef struct s_camera
{
	double	plane_x; //planeX
	double	plane_y; // planeY
	double	current_x; //cameraX
}	t_camera;

typedef struct s_time
{
	double	current_time; //time
	double	previous_time; //oldTime
	double	frame_time; //frametime
	double	movement_speed; //movespeed
	double	rotation_speed; //rotspeed
}	t_time;

typedef struct s_ray
{
	double	direction_x;//raydirX
	double	direction_y;//raydirY
	double	move_to_next_x; //sideDistX
	double	move_to_next_y; //sideDistY
	double	distance_to_next_x; //deltadistX
	double	distance_to_next_y; //deltadistY
	int		step_in_x;//stepX
	int		step_in_y;//stepY
}	t_ray;

typedef struct s_wall
{
	double	shortest_dist_to_wall;
	int		is_hit;
	int		which_side_hit;
}	t_wall;

typedef struct s_draw
{
	int	line_height;
	int	start_pos;
	int	end_pos;
}	t_draw;

void	calculate_closest_point_to_wall(t_wall *wall, t_ray *ray);
void	calculate_height_line(t_wall *wall, t_draw *draw);


#endif