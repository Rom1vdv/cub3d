/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:00:24 by aburnott          #+#    #+#             */
/*   Updated: 2023/05/19 00:07:27 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_putstr(char *str, int fd)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    write(fd, str, i);
}

char	*ft_strdup(char *s, int start, int end)
{
    size_t	len;
    size_t	i;
    char	*dup;

    len = end - start;
    dup = malloc(sizeof(*dup) * len + 1);
    if (!dup)
        return (0);
    i = 0;
    while (s[start] && start < end)
    {
        dup[i] = s[start];
        i++;
        start++;
    }
    dup[i] = '\0';
    return (dup);
}
// {
// 	size_t	len;
// 	size_t	i;
// 	char	*dup;

// 	len = ft_strlen(s);
// 	dup = malloc(sizeof(*dup) * len + 1);
// 	if (!dup)
// 		return (0);
// 	i = 0;
// 	while (s[i])
// 	{
// 		dup[i] = s[i];
// 		i++;
// 	}
// 	dup[i] = '\0';
// 	return (dup);
// }