/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:51:10 by aburnott          #+#    #+#             */
/*   Updated: 2023/06/07 09:57:38 by aburnott         ###   ########.fr       */
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
	int	i;
	int	current;
	
	rgb = ft_split(line, ',');
	if (!rgb)
		return (-1);
	if (rgb[0] && rgb[1] && rgb[2])
	{
		while (i < 3)
		{
			current = ft_atoi(rgb[i]);
			if (current < 0 || current > 255)
				error("Invalid RGB value");
			
		}
	}
	else
		return (-1);
	printf("color set\n");
	printf("ceiling: %d\n", cub->map.ceiling);
	printf("floor: %d\n", cub->map.floor);
	return (1);
}