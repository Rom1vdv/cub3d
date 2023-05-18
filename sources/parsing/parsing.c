/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:22:06 by aburnott          #+#    #+#             */
/*   Updated: 2023/05/18 21:10:29 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		check_texture(char *line)
{
	(void) line;
	return (0);
}

void	catch_textures(int fd)
{
	char *line;
	int res;
	
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == 'N' && line[1] == 'O')
		{
			res = check_texture(line);
			if (res == -1)
			{
				perror("Error\n");
				exit(errno);
			}
		}
		else if (line[0] == 'S' && line[1] == 'O')
		{
			res = check_texture(line);
			if (res == -1)
			{
				perror("Error\n");
				exit(errno);
			}
		}
		else if (line[0] == 'W' && line[1] == 'E')
		{
			res = check_texture(line);
			if (res == -1)
			{
				perror("Error\n");
				exit(errno);
			}
		}
		else if (line[0] == 'E' && line[1] == 'A')
		{
			res = check_texture(line);
			if (res == -1)
			{
				perror("Error\n");
				exit(errno);
			}
		}
		else if (line[0] == 'F' && line[1] == ' ')
		{
			res = check_texture(line);
			if (res == -1)
			{
				perror("Error\n");
				exit(errno);
			}
		}
		else if (line[0] == 'C' && line[1] == ' ')
		{
			res = check_texture(line);
			if (res == -1)
			{
				perror("Error\n");
				exit(errno);
			}
		}	
		else if (line[0] != ' ' && line[0] != '1' && line[0] != '0')
		{
			perror("Error\n");
			exit(errno);
		}
		line = get_next_line(fd);
	}
}

int		check_file(char *file)
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
