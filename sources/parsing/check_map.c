/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 10:33:59 by aburnott          #+#    #+#             */
/*   Updated: 2023/08/09 13:50:43 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map(t_cube *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub->map.y)
	{
		j = 0;
		while (j < cub->map.x - 1)
		{
			if (cub->map.map[i][j] != '1' && cub->map.map[i][j] != ' ')
			{
				if (cub->map.map[i][j] == '0'
						&& (i == 0 || i == cub->map.y - 1))
					return (0);
				else if ((cub->map.map[i][j] == '0'
					&& cub->map.map[i][j + 1] == ' ')
							|| cub->map.map[i][j + 1] == '\0')
					return (0);
				else if (cub->map.map[i][j] == '0'
						&& cub->map.map[i][j - 1] == ' ')
					return (0);
				else if (cub->map.map[i][j] == '0'
						&& cub->map.map[i - 1][j] == ' ')
					return (0);
				else if (cub->map.map[i][j] == '0'
						&& cub->map.map[i + 1][j] == ' ')
					return (0);
				else if (cub->map.map[i][j] != ' '
						&& cub->map.map[i][j] != '1'
						&& cub->map.map[i][j] != '0'
						&& cub->map.map[i][j] != 'N'
						&& cub->map.map[i][j] != 'S'
						&& cub->map.map[i][j] != 'E'
						&& cub->map.map[i][j] != 'W')
				{
					printf("Invalid character in map: <%c> Coordinate: i: %d j: %d\n", cub->map.map[i][j], i, j);
					printf("Map Line:\n%s\n", cub->map.map[i]);
					//************* print a ^ under the invalid character *************
					while (j-- > 0)
						printf(" ");
					printf("^\n");
					//************* end of print ***************************************
				 	return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}
