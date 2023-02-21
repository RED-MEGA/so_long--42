/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 00:25:16 by reben-ha          #+#    #+#             */
/*   Updated: 2023/02/21 23:56:49 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
			if (mlx_x->map[y][x] == 'E' && fp(mlx_x->map, 'C', 'n').i <= 1 
				|| mlx_x->map[y][x] == 'T')
				continue ;
			mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win,
				ft_short_put_to_screen(mlx_x, x, y),
				x * mlx_x->width, y * mlx_x->height);
		}
	}
	mlx_string_put(mlx_x->mlx, mlx_x->mlx_win, 32, 32,
		0xFFFFFF,
		ft_itoa(mlx_x->moves));
}

int	apply_key_do(t_mlx_win *mlx_x, int i, int j)
{
	if (mlx_x->map[i][j] == '1')
		return (-1);
	if ((mlx_x->map[i][j] == 'E' && fp(mlx_x->map, 'C', 'l').i == FAIL))
		return (ft_printf(1, "\033[1;32mBOY! YOU ARE SUCCEEDED\n"),
			ft_destroy(mlx_x), exit(0), 1);
	else if (mlx_x->map[i][j] == 'E')
		return (-1);
	if (mlx_x->map[i][j] == 'T')
		return (ft_printf(1, "\033[1;33mYOU ARE DEAD\n"),
			ft_destroy(mlx_x), exit(0), 1);
	mlx_x->map[i][j] = 'P';
	mlx_x->moves += 1;
	return (0);
}

void	short_apply_key(t_mlx_win *mlx_x, t_loc loc, char *option)
{
	mlx_x->map[loc.i][loc.j] = '0';
	ft_select_img(mlx_x, option);
	ft_put_to_screen(mlx_x);
}

int	apply_key(int keycode, t_mlx_win *mlx_x)
{
	t_loc	loc;
	int		status;

	if (keycode == 53)
		return (ft_destroy(mlx_x), exit(0), 0);
	loc = fp(mlx_x->map, 'P', 'l');
	if (keycode == UP_KEY || keycode == W_KEY)
	{
		status = apply_key_do(mlx_x, loc.i - 1, loc.j);
		if (status == -1)
			return (-1);
		short_apply_key(mlx_x, loc, "back");
	}
	else if (keycode == LEFT_KEY || keycode == A_KEY)
	{
		status = apply_key_do(mlx_x, loc.i, loc.j - 1);
		if (status == -1)
			return (-1);
		short_apply_key(mlx_x, loc, "left");
	}
	else if (keycode == DOWN_KEY || keycode == S_KEY)
	{
		status = apply_key_do(mlx_x, loc.i + 1, loc.j);
		if (status == -1)
			return (-1);
		short_apply_key(mlx_x, loc, "front");
	}
	else if (keycode == RIGHT_KEY || keycode == D_KEY)
	{
		status = apply_key_do(mlx_x, loc.i, loc.j + 1);
		if (status == -1)
			return (-1);
		short_apply_key(mlx_x, loc, "right");
	}
	return (0);
}

int	exit_window(t_mlx_win *mlx_x)
{
	return (ft_destroy(mlx_x), exit(0), 0);
}
