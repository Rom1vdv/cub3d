/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:59:59 by aburnott          #+#    #+#             */
/*   Updated: 2023/05/30 22:02:57 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	ft_putstr(char *str, int fd);
char	*ft_strdup(char *s, int start, int end);
int		ft_strncmp(char *s1, char *s2, size_t n);

#endif