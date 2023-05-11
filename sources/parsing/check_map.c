/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:06:25 by aburnott          #+#    #+#             */
/*   Updated: 2023/05/11 17:11:02 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int check_map(char *map_file)
{
	int fd;
	char *line;
	int i;
	
	line = get_next_line(map_file);
	if (!line)
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			return (0);
		i++;
	}
	free(line);
	while (get_next_line(map_file))
	{
		if (!check_line(line))
			return (0);
		free(line);
	}
	return (1);
}