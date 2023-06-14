/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:26:12 by romvan-d          #+#    #+#             */
/*   Updated: 2023/06/14 16:19:54 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	main(int ac, char **av)
{
	(void) ac;
	(void) av;
	t_cube	cube;
	
	init_mlx(&cube.mlx, &cube);
	printf("salut");
	raycasting(&cube);
	return (0);
}