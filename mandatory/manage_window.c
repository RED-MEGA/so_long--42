/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 00:25:16 by reben-ha          #+#    #+#             */
/*   Updated: 2023/02/17 03:11:10 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_to_screen(t_mlx_win *mlx_x)
{
	void	*img_ch;
	int		x;
	int		y;

	mlx_clear_window(mlx_x->mlx, mlx_x->mlx_win);
	y = -1;
	while (++y < mlx_x->y)
	{
		x = -1;
		while (++x < mlx_x->x)
		{
			if (mlx_x->map[y][x] == '0')
				img_ch = mlx_x->img.floor;
			else if (mlx_x->map[y][x] == '1')
				img_ch = mlx_x->img.wall;
			else if (mlx_x->map[y][x] == 'C')
				img_ch = mlx_x->img.coin;
			else if (mlx_x->map[y][x] == 'E')
				img_ch = mlx_x->img.exit;
			else if (mlx_x->map[y][x] == 'P')
				img_ch = mlx_x->img.player.front.frame_3;
			mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, img_ch, x * mlx_x->width, y * mlx_x->height);
		}
	}
}

int	apply_key(int keycode, t_mlx_win *mlx_x)
{
	t_loc	loc;

	if (keycode == 53)
		exit(0);
	loc = fp(mlx_x->map, 'P', 'l');
	if (keycode == 126 || keycode == 13)
	{
		if (mlx_x->map[loc.i - 1][loc.j] == '1')
			return (-1);
		if (mlx_x->map[loc.i - 1][loc.j] == 'E' && fp(mlx_x->map, 'C', 'l').i == FAIL)
			exit(1);
		else if (mlx_x->map[loc.i - 1][loc.j] == 'E')
			return (-1);
		mlx_x->map[loc.i - 1][loc.j] = 'P';
		mlx_x->map[loc.i][loc.j] = '0';
		mlx_x->moves += 1;
	}
	else if (keycode == 123 || keycode == 0)
	{
		if (mlx_x->map[loc.i][loc.j - 1] == '1')
			return (-1);
		if (mlx_x->map[loc.i][loc.j - 1] == 'E' && fp(mlx_x->map, 'C', 'l').i == FAIL)
			exit(1);
		else if (mlx_x->map[loc.i][loc.j - 1] == 'E')
			return (-1);
		mlx_x->map[loc.i][loc.j - 1] = 'P';
		mlx_x->map[loc.i][loc.j] = '0';
		mlx_x->moves += 1;
	}
	else if (keycode == 125 || keycode == 1)
	{
		if (mlx_x->map[loc.i + 1][loc.j] == '1')
			return (-1);
		if (mlx_x->map[loc.i + 1][loc.j] == 'E' && fp(mlx_x->map, 'C', 'l').i == FAIL)
			exit(1);
		else if (mlx_x->map[loc.i + 1][loc.j] == 'E')
			return (-1);
		mlx_x->map[loc.i + 1][loc.j] = 'P';
		mlx_x->map[loc.i][loc.j] = '0';
		mlx_x->moves += 1;
	}
	else if (keycode == 124 || keycode == 2)
	{
		if (mlx_x->map[loc.i][loc.j + 1] == '1')
			return (-1);
		if (mlx_x->map[loc.i][loc.j + 1] == 'E' && fp(mlx_x->map, 'C', 'l').i == FAIL)
			exit(1);
		else if (mlx_x->map[loc.i][loc.j + 1] == 'E')
			return (-1);
		mlx_x->map[loc.i][loc.j + 1] = 'P';
		mlx_x->map[loc.i][loc.j] = '0';
		mlx_x->moves += 1;
	}
	ft_put_to_screen(mlx_x);
	mlx_string_put(mlx_x->mlx, mlx_x->mlx_win, 32, 32, 0xFFFFFF, ft_itoa(mlx_x->moves));
	return (0);
}

int	exit_window(void *param)
{
	(void)param;
	exit(0);
}
