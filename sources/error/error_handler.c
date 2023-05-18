/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:39:01 by aburnott          #+#    #+#             */
/*   Updated: 2023/05/18 22:06:36 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error(char *str, int code, int need_free)
{
    (void) need_free;

    if (code)
        perror("Error");
    else
    {
        ft_putstr("Error: ", 2);
        ft_putstr(str, 2);
    }
    exit(errno);
}