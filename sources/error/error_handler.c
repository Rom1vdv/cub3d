/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:39:01 by aburnott          #+#    #+#             */
/*   Updated: 2023/06/07 16:36:25 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error(char *str, int code, int need_free)
{
	(void) need_free;
	if (code)
		perror("Error\n");
	else
	{
		ft_putstr("Error\n", 2);
		ft_putstr(str, 2);
	}
	exit(errno);
}
