/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:28:19 by aburnott          #+#    #+#             */
/*   Updated: 2023/06/02 16:11:36 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_textures
{
    char    *no;
    char    *so;
    char    *we;
    char    *ea;
    char    *s;
    char    *f;
    char    *c;
}   t_textures;

typedef struct s_map
{
    char    **map;
    int     x;
    int     y;
}   t_map;

typedef struct s_xpm_file
{
    int     width;
    int     height;
    void    *wall_no;
    void    *wall_so;
    void    *wall_we;
    void    *wall_ea;
}   t_xpm_file;

typedef struct s_cub
{
    t_textures  textures;
    t_map       map;
    t_xpm_file  xpm_file;
}   t_cub;

int     check_file(char *file, t_cub *cub);
int		get_map_size(char *line, t_cub *cub);

#endif