/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:28:19 by aburnott          #+#    #+#             */
/*   Updated: 2023/05/19 00:09:19 by aburnott         ###   ########.fr       */
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


int		check_file(char *file);

#endif