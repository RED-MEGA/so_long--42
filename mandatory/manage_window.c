/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 00:25:16 by reben-ha          #+#    #+#             */
/*   Updated: 2023/02/18 22:46:32 by reben-ha         ###   ########.fr       */
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
	img_ch = NULL;
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
			else if (mlx_x->map[y][x] == 'P')
				img_ch = mlx_x->img.player.front.frame_3;
			else if (mlx_x->map[y][x] == 'T')
				img_ch = mlx_x->img.enemy;
			else if (mlx_x->map[y][x] == 'E' && fp(mlx_x->map, 'C', 'l').i != -1)
				img_ch = mlx_x->img.exit;
			else if (mlx_x->map[y][x] == 'E')
				img_ch = mlx_x->img.exit_hole.frame_1;
			mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, img_ch, x * mlx_x->width, y * mlx_x->height);
		}
	}
}

int	apply_key_do(t_mlx_win *mlx_x, int i, int j)
{
	if (mlx_x->map[i][j] == '1')
		return (-1);
	if (mlx_x->map[i][j] == 'E' && fp(mlx_x->map, 'C', 'l').i == FAIL
			|| mlx_x->map[i][j] == 'T')
		exit(0);
	else if (mlx_x->map[i][j] == 'E')
		return (-1);
	mlx_x->map[i][j] = 'P';
	mlx_x->moves += 1;
	return (0);
}

int	apply_key(int keycode, t_mlx_win *mlx_x)
{
	t_loc	loc;
	int		status;

	if (keycode == 53)
		exit(0);
	loc = fp(mlx_x->map, 'P', 'l');
	if (keycode == UP_KEY || keycode == W_KEY)
	{
		status = apply_key_do(mlx_x, loc.i - 1, loc.j);
		if (status == -1)
			return (-1);
		mlx_x->map[loc.i][loc.j] = '0';
	}
	else if (keycode == LEFT_KEY || keycode == A_KEY)
	{
		status = apply_key_do(mlx_x, loc.i, loc.j - 1);
		if (status == -1)
			return (-1);
		mlx_x->map[loc.i][loc.j] = '0';
	}
	else if (keycode == DOWN_KEY || keycode == S_KEY)
	{
		status = apply_key_do(mlx_x, loc.i + 1, loc.j);
		if (status == -1)
			return (-1);
		mlx_x->map[loc.i][loc.j] = '0';
	}
	else if (keycode == RIGHT_KEY || keycode == D_KEY)
	{
		status = apply_key_do(mlx_x, loc.i, loc.j + 1);
		if (status == -1)
			return (-1);
		mlx_x->map[loc.i][loc.j] = '0';
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
