/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:39:18 by aburnott          #+#    #+#             */
/*   Updated: 2023/09/13 13:04:22 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

void	error(t_cube *cub, char *str, int code);
void	ft_free_end(t_cube *cub);
void	ft_free(char **str, char *line);

#endif