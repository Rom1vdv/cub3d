/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:36:12 by aburnott          #+#    #+#             */
/*   Updated: 2023/06/07 09:49:14 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    init_struc(char *av)
{
    t_cub       cub;
    
	cub.a_error = 0;
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

int main(int ac, char **av)
{
    //t_mlx  mlx;

	if (ac != 2)
        error("Wrong number of arguments\n", 0, 0);
    if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0)
    {
        error("Wrong file extension\n", 0, 0);
    }
    init_struc(av[1]);
	printf("init of mlx will be called");
    //if (!init_mlx(&mlx))
        //error("Error while initializing mlx\n", 0, 0);
    //run_mlx(&mlx);
	return (0);
}