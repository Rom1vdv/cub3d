/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:36:12 by aburnott          #+#    #+#             */
/*   Updated: 2023/06/19 18:05:00 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struc(char *av)
{
    t_cube	cub;

	cub.textures.no = 0;
	cub.textures.so = 0;
	cub.textures.we = 0;
	cub.textures.ea = 0;
	cub.textures.f = 0;
	cub.textures.c = 0;
	cub.map.map = 0;
	cub.map.start_line = 0;
	cub.map.x = 0;
	cub.map.y = 0;
	cub.map.player_found = 0;
	cub.map.player_x = 0;
	cub.map.player_y = 0;
	cub.map.player_patch = 0;
	cub.map.map_error = 0;
	cub.map.floor = 0;
	cub.map.ceiling = 0;
	cub.xpm_file.wall_no = 0;
	cub.xpm_file.wall_so = 0;
	cub.xpm_file.wall_we = 0;
	cub.xpm_file.wall_ea = 0;
	cub.xpm_file.width = 0;
	cub.xpm_file.height = 0;
	cub.player.director_vector_x = 1;
	cub.player.director_vector_y = 0;
	cub.player.current_square_x = 0;
	cub.player.current_square_y = 0;
	cub.camera.plane_x = 0;
	cub.camera.plane_y = 0.66;
	cub.camera.plane_y = 0.66;
	cub.camera.current_x = 0;
	cub.ray.direction_x = 0;
	cub.ray.direction_y = 0;
	cub.ray.move_to_next_x = 0;
	cub.ray.move_to_next_y = 0;
	cub.ray.distance_to_next_x = 0;
	cub.ray.distance_to_next_y = 0;
	cub.ray.step_in_x = 0;
	cub.ray.step_in_y = 0;
	cub.wall.shortest_dist_to_wall = 0;
	cub.wall.is_hit = 0;
	cub.wall.which_side_hit = 0;
	cub.draw.end_pos = 0;
	cub.draw.start_pos = 0;
	cub.draw.line_height = 0;
	check_file(av, &cub);
    init_mlx(&cub.mlx, &cub);
}

int	main(int ac, char **av)
{
	(void)ac;
	
	init_struc(av[1]);
	return (0);
}