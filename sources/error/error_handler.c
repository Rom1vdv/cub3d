/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:39:01 by aburnott          #+#    #+#             */
/*   Updated: 2023/09/22 14:07:29 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_end(t_cube *cub)
{
	int	i;

	i = 0;
	if (cub->map.map)
	{
		while (i < cub->map.y)
		{
			free(cub->map.map[i]);
			i++;
		}
		free(cub->map.map);
	}
	if (cub->textures.no)
		free(cub->textures.no);
	if (cub->textures.so)
		free(cub->textures.so);
	if (cub->textures.we)
		free(cub->textures.we);
	if (cub->textures.ea)
		free(cub->textures.ea);
}

void	ft_free(char **str, char *line)
{
	int	i;

	i = 0;
	if (line)
		free(line);
	else if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}

void	error(t_cube *cub, char *str, int code)
{
	if (code)
		perror("Error\n");
	else
	{
		ft_putstr("Error\n", 2);
		ft_putstr(str, 2);
	}
	if (cub)
		ft_free_end(cub);
	exit(errno);
}
