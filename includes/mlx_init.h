/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:06:07 by aburnott          #+#    #+#             */
/*   Updated: 2023/06/02 15:41:28 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_INIT_H
# define MLX_INIT_H

# ifndef WIDTH
#  define WIDTH 640
# endif
# ifndef HEIGHT
#  define HEIGHT 480
# endif

typedef struct s_mlx
{
	void	*init;
	void	*win;
	void	*img;
	char	*addr;
}	t_mlx;

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

int		init_mlx(t_mlx *mlx);
int		run_mlx(t_mlx *mlx);
int		key_pressed(int keycode, t_mlx *mlx);
int		ft_close(t_mlx *mlx);
int		ft_released(int keycode, t_mlx *mlx);

#endif