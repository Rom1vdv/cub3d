/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:46:32 by romvan-d          #+#    #+#             */
/*   Updated: 2023/06/20 15:14:14 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	transformations(t_cube *cube)
{
	movements(cube);
}

int	cube_loop(t_cube *cube)
{
	transformations(cube);
	render(cube);
	return (0);
}