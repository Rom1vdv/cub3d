/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:22:06 by aburnott          #+#    #+#             */
/*   Updated: 2023/09/13 13:02:07 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_color(char *line, int type, t_cube *cub)
{
	if (type == 1)
		set_color(cub, ft_strdup(line, 2, ft_strlen(line)), 2);
	else if (type == 2)
		set_color(cub, ft_strdup(line, 2, ft_strlen(line)), 1);
	return (0);
}

int	get_texture(char *line, int type, t_cube *cub)
{
	if (type == 1)
	{
		cub->textures.no = \
			parse_texture(ft_strdup(line, 3, ft_strlen(line) - 1));
	}
	else if (type == 2)
	{
		cub->textures.so = \
			parse_texture(ft_strdup(line, 3, ft_strlen(line) - 1));
	}
	else if (type == 3)
	{
		cub->textures.we = \
			parse_texture(ft_strdup(line, 3, ft_strlen(line) - 1));
	}	
	else if (type == 4)
	{
		cub->textures.ea = \
			parse_texture(ft_strdup(line, 3, ft_strlen(line) - 1));
	}
	return (0);
}

static void	continue_catch(char *line, t_cube *cub, int res)
{
	if (line[0] == 'N' && line[1] == 'O')
		res = get_texture(line, 1, cub);
	else if (line[0] == 'S' && line[1] == 'O')
		res = get_texture(line, 2, cub);
	else if (line[0] == 'W' && line[1] == 'E')
		res = get_texture(line, 3, cub);
	else if (line[0] == 'E' && line[1] == 'A')
		res = get_texture(line, 4, cub);
	else if (line[0] == 'F' && line[1] == ' ')
		res = get_color(line, 1, cub);
	else if (line[0] == 'C' && line[1] == ' ')
		res = get_color(line, 2, cub);
	else if ((line[0] != '\n') || res == -1)
	{
		error(cub, "Something went wrong with map file\n", 0);
	}
}

void	catch_textures(char *line, t_cube *cub, int line_count)
{
	int		res;
	int		i;

	res = 0;
	i = 0;
	if (line[0] == ' ' || line[0] == '1')
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '1')
		{
			if (cub->map.start_line == 0)
				cub->map.start_line = line_count;
			res = get_map_size(line, cub);
		}
		else
			error(cub, "Something went wrong with the map\n", 0);
	}
	else
		continue_catch(line, cub, res);
}

int	check_file(char *file, t_cube *cub)
{
	int		fd;
	int		line_count;
	char	*line;

	line = "";
	line_count = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error(cub, "Can't open file\n", 1);
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		line_count++;
		catch_textures(line, cub, line_count);
		free(line);
	}
	close(fd);
	call_suite(cub, file);
	return (0);
}
