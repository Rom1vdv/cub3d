/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 10:33:59 by aburnott          #+#    #+#             */
/*   Updated: 2023/06/04 10:36:37 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_map(t_cub *cub)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < cub->map.x)
	{
		j = 0;
		while (j < cub->map.y)
		{
			if (cub->map.map[i][j] != '1' && cub->map.map[i][j] != ' ')
			{
				if (cub->map.map[i][j] != '0' && cub->map.map[i][j] != '2')
					return (0);
				if (cub->map.map[i][j + 1] == ' ' || cub->map.map[i][j - 1] == ' ')
					return (0);
				if (cub->map.map[i + 1][j] == ' ' || cub->map.map[i - 1][j] == ' ')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}