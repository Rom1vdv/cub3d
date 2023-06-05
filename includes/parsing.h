/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:28:19 by aburnott          #+#    #+#             */
/*   Updated: 2023/06/05 22:18:12 by aburnott         ###   ########.fr       */
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
    char    *f;
    char    *c;
}   t_textures;

typedef struct s_map
{
    char    **map;
	int    	start_line;
    int     x;
    int     y;
	int		player_found;
	int		player_x;
	int		player_y;
	int		map_error;
	int		player_patch;
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
char	*check_texture(char *path);
int		store_map(char *file, t_cub *cub);
int		check_map(t_cub *cub);

#endif