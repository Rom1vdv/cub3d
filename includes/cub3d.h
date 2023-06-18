/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:20:03 by aburnott          #+#    #+#             */
/*   Updated: 2023/06/18 21:42:57 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
/* Standard Libraries */

# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>
# include <stdio.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <string.h>
# include <stdint.h>

/* Struct and Defines */

# include "structs.h"
# include "defines.h"

/* MlX components */
# include "mlx.h"
# include "mlx_handling.h"

/* Parsing */
# include "parsing.h"

/* Errors */

# include "error.h"

/* Utils */

# include "utils.h"

/* Raycastign */

# include "raycasting.h"

/* 42 Libraries */

# include "../sources/gnl/get_next_line.h"

#endif