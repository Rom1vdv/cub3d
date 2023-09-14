/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 22:52:23 by aburnott          #+#    #+#             */
/*   Updated: 2023/09/14 10:38:20 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_count(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if ((s[i] != c) && s[i])
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count + 1);
}

char	*word(int *j_int, char const *s, char c)
{
	int		len;
	char	*buf;
	int		i;

	i = 0;
	len = 0;
	while (s[*j_int] == c)
		(*j_int)++;
	while ((s[*j_int + len] != c) && s[*j_int + len])
		len++;
	buf = ft_malloc((len + 1) * sizeof(*buf));
	if (!buf)
		return (0);
	while (i < len)
	{
		buf[i] = s[*j_int];
		i++;
		*j_int = *j_int + 1;
	}
	buf[i] = 0;
	return (buf);
}

char	**free_all_c(char **s, int limit)
{
	int	index;

	index = 0;
	while (index < limit)
	{
		free(s[index]);
		index ++;
	}
	free(s);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		count;
	int		i;
	int		j;

	if (!s)
		return (0);
	i = 0;
	j = 0;
	count = ft_count(s, c);
	strings = ft_malloc(count * sizeof(char *));
	if (!strings)
		return (0);
	while (i < count - 1)
	{
		strings[i] = word(&j, s, c);
		if (!strings[i])
			return (free_all_c(strings, i));
		i++;
	}
	strings[i] = 0;
	return (strings);
}
