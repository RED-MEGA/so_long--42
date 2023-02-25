/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 00:25:16 by reben-ha          #+#    #+#             */
/*   Updated: 2023/02/25 16:32:36 by reben-ha         ###   ########.fr       */
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

int	apply_key_do(t_mlx_win *mlx_x, int i, int j)
{
	if (mlx_x->map[i][j] == '1')
		return (-1);
	if ((mlx_x->map[i][j] == 'E' && fp(mlx_x->map, 'C', 'l').i == FAIL))
		return (ft_printf(1, "\033[1;32mBOY! YOU HAVE SUCCEEDED\n"),
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

int	short_apply_key(t_mlx_win *mlx_x, t_loc loc, char *option)
{
	int	status;

	if (ft_strncmp(option, "back", 4) == 0)
		status = apply_key_do(mlx_x, loc.i - 1, loc.j);
	else if (ft_strncmp(option, "left", 4) == 0)
		status = apply_key_do(mlx_x, loc.i, loc.j - 1);
	else if (ft_strncmp(option, "front", 5) == 0)
		status = apply_key_do(mlx_x, loc.i + 1, loc.j);
	else if (ft_strncmp(option, "right", 5) == 0)
		status = apply_key_do(mlx_x, loc.i, loc.j + 1);
	if (status == -1)
		return (-1);
	mlx_x->map[loc.i][loc.j] = '0';
	ft_select_img(mlx_x, option);
	ft_put_to_screen(mlx_x);
	return (0);
}

int	apply_key(int keycode, t_mlx_win *mlx_x)
{
	t_loc	loc;
	int		status;

	if (keycode == 53)
		return (ft_destroy(mlx_x), exit(0), 0);
	loc = fp(mlx_x->map, 'P', 'l');
	if (keycode == UP_KEY || keycode == W_KEY)
		status = short_apply_key(mlx_x, loc, "back");
	else if (keycode == LEFT_KEY || keycode == A_KEY)
		status = short_apply_key(mlx_x, loc, "left");
	else if (keycode == DOWN_KEY || keycode == S_KEY)
		status = short_apply_key(mlx_x, loc, "front");
	else if (keycode == RIGHT_KEY || keycode == D_KEY)
		status = short_apply_key(mlx_x, loc, "right");
	return (status);
}

int	exit_window(t_mlx_win *mlx_x)
{
	return (ft_destroy(mlx_x), exit(0), 0);
}
