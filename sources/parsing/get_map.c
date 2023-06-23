/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:33:24 by aburnott          #+#    #+#             */
/*   Updated: 2023/06/23 14:53:31 by aburnott         ###   ########.fr       */
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
	cub->map.map = ft_malloc(sizeof(char *) * cub->map.x);
	while (i < cub->map.x)
	{
		cub->map.map[cub->map.x - 1] = ft_malloc(sizeof(char) * cub->map.y);
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
	while (i < cub->map.x)
	{
		line = read_current_line(fd);
		if (!line)
			return (-1);
		cub->map.map[i] = ft_strdup_modif(line, 0, (cub->map.y - 1));
		free(line);
		i++;
	}
	close(fd);
	// print map
	i = 0;
	printf("map stored:\n");
	while (i < cub->map.x)
	{
		printf("|%s|\n", cub->map.map[i]);
		i++;
	}
	// end print map
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
			cub->map.player_x = (double)cub->map.x + 0.5;
			cub->map.player_y = (double)i + 0.5;
            cub->map.player_found = 1;
		}
		i++;
	}
	if (line[i - 2] == '1' || line[i - 1])
	{
		cub->map.x += 1;
		if (i > cub->map.y)
			cub->map.y = i;
		return (0);
	}
	return (-1);
}
