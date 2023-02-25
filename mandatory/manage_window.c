/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 00:25:16 by reben-ha          #+#    #+#             */
/*   Updated: 2023/02/25 18:47:02 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_select_img(t_mlx_win *mlx_x, char *option)
{
	if (ft_strncmp(option, "front", 5) == 0)
		mlx_x->img.player.main = mlx_x->img.player.front;
	else if (ft_strncmp(option, "back", 4) == 0)
		mlx_x->img.player.main = mlx_x->img.player.back;
	else if (ft_strncmp(option, "left", 4) == 0)
		mlx_x->img.player.main = mlx_x->img.player.left;
	else if (ft_strncmp(option, "right", 5) == 0)
		mlx_x->img.player.main = mlx_x->img.player.right;
	else
		return ;
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
