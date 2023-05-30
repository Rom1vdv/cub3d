/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:22:06 by aburnott          #+#    #+#             */
/*   Updated: 2023/05/31 01:11:37 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_color(char *line, int type, t_cub *cub)
{
    if (type == 1)
		cub->textures.f = ft_strdup(line, 2, ft_strlen(line));
	else if (type == 2)
		cub->textures.c = ft_strdup(line, 2, ft_strlen(line));
	return (0);
}

int	get_texture(char *line, int type, t_cub *cub)
{
	if (type == 1)
		cub->textures.no = ft_strdup(line, 3, ft_strlen(line));
	else if (type == 2)
		cub->textures.so = ft_strdup(line, 3, ft_strlen(line));
	else if (type == 3)
		cub->textures.we = ft_strdup(line, 3, ft_strlen(line));
	else if (type == 4)
		cub->textures.ea = ft_strdup(line, 3, ft_strlen(line));
	else if (type == 5)
		cub->textures.s = ft_strdup(line, 3, ft_strlen(line));
	return (0);
}

void	catch_textures(char *line, t_cub *cub)
{
	int		res;
	
	res = 0;
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
	else if ((line[0] != '\n' && line[0] != '1'
			&& line[0] != '0' && line[0] != ' ') || res == -1)
		error("Something went wrong with map file\n", 0, 0);
}

int	check_file(char *file, t_cub *cub)
{
    int	fd;
    char *line;

	fd = open(file, O_RDONLY);
    if (fd == -1)
        error("Can't open file\n", 1, 0);
    while (line)
    {
        line = get_next_line(fd);
        catch_textures(line, cub);
        free(line);
    }
	
	return (0);
}
