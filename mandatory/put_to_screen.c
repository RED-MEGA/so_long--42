/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:15:16 by reben-ha          #+#    #+#             */
/*   Updated: 2023/02/25 18:15:49 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_text(t_mlx_win *mlx_x)
{
	mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win,
		mlx_x->img.blade,
		0, 0);
	mlx_string_put(mlx_x->mlx, mlx_x->mlx_win, 188, 39,
		0xFF0000,
		ft_strjoin("| Moves:", ft_itoa(mlx_x->moves)));
	mlx_string_put(mlx_x->mlx, mlx_x->mlx_win, 150, 40,
		0x1D1CE5,
		ft_strjoin("C:", ft_itoa(fp(mlx_x->map, 'C', 'n').i)));
}

char	*ft_short_put_to_screen(t_mlx_win *mlx_x, int x, int y)
{
	if (mlx_x->map[y][x] == '0')
		return (mlx_x->img.floor);
	else if (mlx_x->map[y][x] == '1')
		return (mlx_x->img.wall);
	else if (mlx_x->map[y][x] == 'C')
		return (mlx_x->img.coin);
	else if (mlx_x->map[y][x] == 'P')
		return (mlx_x->img.player.main);
	else if (mlx_x->map[y][x] == 'T')
		return (mlx_x->img.enemy);
	else if (mlx_x->map[y][x] == 'E' && fp(mlx_x->map, 'C', 'n').i > 1)
		return (mlx_x->img.exit);
	return (NULL);
}

void	ft_put_to_screen(t_mlx_win *mlx_x)
{
	static int	first;
	void		*img_ch;
	int			x;
	int			y;

	y = -1;
	while (++y < mlx_x->y)
	{
		x = -1;
		while (++x < mlx_x->x)
		{
			if ((mlx_x->map[y][x] == 'E'
				&& fp(mlx_x->map, 'C', 'n').i <= 1))
				continue ;
			mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win,
				ft_short_put_to_screen(mlx_x, x, y),
				x * mlx_x->width, y * mlx_x->height);
		}
	}
	ft_put_text(mlx_x);
}
