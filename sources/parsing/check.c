/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:51:10 by aburnott          #+#    #+#             */
/*   Updated: 2023/06/15 15:07:42 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*check_texture(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (path);
}

void	set_color(t_cube *cub, char *line, int type)
{
	char	**rgb;
	int		i;
	int		current;

	rgb = ft_split(line, ',');
	if (rgb[0] && rgb[1] && rgb[2])
	{
		i = 0;
		current = 0;
		while (rgb[i])
		{
			current = ft_atoi(rgb[i]);
			if (current < 0 || current > 255)
				error("Invalid RGB value", 0, 0);
			if (type == 1)
				cub->map.ceiling = (cub->map.ceiling << 8) + current;
			else
				cub->map.floor = (cub->map.floor << 8) + current;
			i++;
		}
	}
	else
		error("Invalid RGB value", 0, 0);
}
