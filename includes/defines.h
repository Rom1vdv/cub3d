/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:19:17 by romvan-d          #+#    #+#             */
/*   Updated: 2023/06/19 17:10:26 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# ifndef SCREEN_WIDTH
#  define SCREEN_WIDTH 640
# endif
# ifndef SCREEN_HEIGHT
#  define SCREEN_HEIGHT 480
# endif

# ifndef NORTH_SOUTH
# define NORTH_SOUTH 1
# endif
# ifndef EAST_WEST
# define EAST_WEST 0
# endif

# ifndef MOV_SPEED
# define MOV_SPEED 0.1
# endif
# ifndef ROT_SPEED
# define ROT_SPEED 0.01
# endif

# ifndef TEXTURE_WIDTH
# define TEXTURE_WIDTH 64
# endif
# ifndef TEXTURE_HEIGHT
# define TEXTURE_HEIGHT 64
# endif

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_DESTROY = 17
};

enum
{
	KEY_A = 0,
	KEY_D = 2,
	KEY_S = 1,
	KEY_W = 13,
	KEY_ESC = 53,
	KEY_RIGHT = 124,
	KEY_LEFT = 123,
};

#endif