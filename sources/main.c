/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:36:12 by aburnott          #+#    #+#             */
/*   Updated: 2023/06/15 15:54:29 by romvan-d         ###   ########.fr       */
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
	check_file(av, &cub);
}

int	main(int ac, char **av)
{
	(void) ac;
	(void) av;
	t_cube	cube;
	
	init_mlx(&cube.mlx, &cube);
	printf("salut");
	raycasting(&cube);
	return (0);
}