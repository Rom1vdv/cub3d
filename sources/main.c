/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:36:12 by aburnott          #+#    #+#             */
/*   Updated: 2023/06/02 16:23:23 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    init_struc(char *av)
{
    t_cub       cub;
    
    cub.textures.no = 0;
    cub.textures.so = 0;
    cub.textures.we = 0;
    cub.textures.ea = 0;
    cub.textures.s = 0;
    cub.textures.f = 0;
    cub.textures.c = 0;
    cub.map.map = 0;
    cub.map.x = 0;
    cub.map.y = 0;
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
    t_mlx  mlx;

	if (ac != 2)
        error("Wrong number of arguments\n", 0, 0);
    if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0)
    {
        error("Wrong file extension\n", 0, 0);
    }
    init_struc(av[1]);
    if (!init_mlx(&mlx))
        error("Error while initializing mlx\n", 0, 0);
    run_mlx(&mlx);
	return (0);
}