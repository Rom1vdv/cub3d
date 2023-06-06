/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:51:10 by aburnott          #+#    #+#             */
/*   Updated: 2023/06/06 16:47:17 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*check_texture(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (path);
}

int	set_color(t_cub *cub, char *line, int type)
{
	char **rgb;
	
	rgb = ft_split(line, ',');
	if (!rgb)
		return (-1);
	if (rgb[0] && rgb[1] && rgb[2])
	{
		if (type == 1)
		{
			cub->map.ceiling = ft_atoi(rgb[0]);
			cub->map.ceiling = (cub->map.ceiling << 8) + ft_atoi(rgb[1]);
			cub->map.ceiling = (cub->map.ceiling << 8) + ft_atoi(rgb[2]);
		}
		else if (type == 2)
		{
			cub->map.floor = ft_atoi(rgb[0]);
			cub->map.floor = (cub->map.floor << 8) + ft_atoi(rgb[1]);
			cub->map.floor = (cub->map.floor << 8) + ft_atoi(rgb[2]);
		}
	}
	else
		return (-1);
	printf("color set\n");
	printf("ceiling: %d\n", cub->map.ceiling);
	printf("floor: %d\n", cub->map.floor);
	return (1);
}