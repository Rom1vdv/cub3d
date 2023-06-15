/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:28:19 by aburnott          #+#    #+#             */
/*   Updated: 2023/06/15 15:04:36 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include "cub3d.h"

int		check_file(char *file, t_cube *cub);
int		get_map_size(char *line, t_cube *cub);
int		store_map(char *file, t_cube *cub);
int		check_map(t_cube *cub);
char	*check_texture(char *path);
void	set_color(t_cube *cub, char *line, int type);

#endif