/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:22:06 by aburnott          #+#    #+#             */
/*   Updated: 2023/05/19 00:08:52 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_texture(char *line, int type)
{
	//int	i;
	t_textures	textures;

	(void) textures;
	if (type == 1)
	{
		textures.no = ft_strdup(line, 3, ft_strlen(line));
		printf("NO: %s\n", textures.no);
	}
	else if (type == 2)
	{
		textures.so = ft_strdup(line, 3, ft_strlen(line));
		printf("SO: %s\n", textures.so);
	}
	else if (type == 3)
	{
		textures.we = ft_strdup(line, 3, ft_strlen(line));
		printf("WE: %s\n", textures.we);
	}
	else if (type == 4)
	{
		textures.ea = ft_strdup(line, 3, ft_strlen(line));
		printf("EA: %s\n", textures.ea);
	}
	else if (type == 0)
	{
		textures.f = ft_strdup(line, 2, ft_strlen(line));
		printf("F: %s\n", textures.f);
	}
	else if (type == 0)
	{
		textures.c = ft_strdup(line, 2, ft_strlen(line));
		printf("C: %s\n", textures.c);
	}
	return (0);
}

void	catch_textures(int fd)
{
	char	*line;
	int		res;

	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == 'N' && line[1] == 'O')
			res = check_texture(line, 1);
		else if (line[0] == 'S' && line[1] == 'O')
			res = check_texture(line, 2);
		else if (line[0] == 'W' && line[1] == 'E')
			res = check_texture(line, 3);
		else if (line[0] == 'E' && line[1] == 'A')
			res = check_texture(line, 4);
		else if (line[0] == 'F' && line[1] == ' ')
			res = check_texture(line, 0);
		else if (line[0] == 'C' && line[1] == ' ')
			res = check_texture(line, 0);
		else if ((line[0] != '\n' && line[0] != '1'
				&& line[0] != '0' && line[0] != ' ') || res == -1)
			error("Wrong character in map\n", 0, 0);
		line = get_next_line(fd);
	}
	close(fd);
}

int	check_file(char *file)
{
    int	fd;
	//int	res;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n");
		exit(errno);
	}
	catch_textures(fd);
	return (0);
}
