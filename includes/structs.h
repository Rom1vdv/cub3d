/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:37:13 by romvan-d          #+#    #+#             */
/*   Updated: 2023/06/20 09:50:08 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

#include "cub3d.h"

typedef struct s_mlx
{
	void	*init;
	void	*win;
	void	*img;
	char	*address;
	int	endian;
	int	bits_per_pixel;
	int	line_length;
}	t_mlx;

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

typedef struct s_map
{
	char			**map;
	char			player_orientation;
	int				start_line;
	int				x;
	int				y;
	int				player_found;
	int				player_x;
	int				player_y;
	int				map_error;
	int				player_patch;
	unsigned int	floor;
	unsigned int	ceiling;
}	t_map;

typedef struct s_textures
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
}	t_textures;

typedef struct s_xpm_file
{
	int		width;
	int		height;
	void	*wall_no;
	void	*wall_so;
	void	*wall_we;
	void	*wall_ea;
}	t_xpm_file;

typedef struct s_cube
{
	t_player	player;
	t_camera	camera;
	t_ray		ray;
	t_wall		wall;
	t_draw		draw;
	t_mlx		mlx;
	t_textures	textures;
	t_xpm_file	xpm_file;
	t_map		map;
}	t_cube;

#endif