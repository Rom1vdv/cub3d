/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:33:24 by aburnott          #+#    #+#             */
/*   Updated: 2023/08/09 15:23:08 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*read_current_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	return (line);
}

int	store_map(char *file, t_cube *cub)
{
	int		fd;
	int		i;
	char	*line;
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	cub->map.map = ft_malloc(sizeof(char *) * cub->map.y);
	while (i < cub->map.y)
	{
		cub->map.map[cub->map.y - 1] = ft_malloc(sizeof(char) * cub->map.x);
		i++;
	}
	i = 0;
	while (i < cub->map.start_line - 1)
	{
		line = read_current_line(fd);
		if (!line)
			return (-1);
		free(line);
		i++;
	}
	i = 0;
	while (i < cub->map.y)
	{
		line = read_current_line(fd);
		if (!line)
			return (-1);
		cub->map.map[i] = ft_strdup_modif(line, 0, (cub->map.x - 1));
		free(line);
		i++;
	}
	close(fd);
	// print map
	i = 0;
	printf("map stored:\n");
	while (i < cub->map.y)
	{
		printf("|%s|\n", cub->map.map[i]);
		i++;
	}
	cub->map.map[(int)cub->map.player_x][(int)cub->map.player_y] = '0';
	ft_swap_double(&cub->map.player_x, &cub->map.player_y);
	return (0);
}

int	get_map_size(char *line, t_cube *cub)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'W' || line[i] == 'E')
		{
			cub->map.player_x = i;
			cub->map.player_y = cub->map.y;
			cub->map.player_found = 1;
			cub->map.player_orientation = line[i];
		}
		i++;
	}
	if (line[i - 2] == '1' || line[i - 1])
	{
		cub->map.y += 1;
		if (i > cub->map.x)
			cub->map.x = i;
		return (0);
	}
	return (-1);
}
