/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 05:32:04 by reben-ha          #+#    #+#             */
/*   Updated: 2023/02/17 18:39:22 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_sleep(int time)
{
	int	i;

	i = 0;
  	while (i < (time * 50000000))
		i++;;
}

int	midgard_hole(t_mlx_win *mlx_x)
{
	t_loc		loc;
	static int	fps;

	loc = fp(mlx_x->map, 'E', 'l');
	if (fps == 1)
	{
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_1, loc.j * 100, loc.i * 100);
		ft_sleep(1);
		mlx_do_sync(mlx_x->mlx);
	}
	else if (fps == 2)
	{
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_2, loc.j * 100, loc.i * 100);
		ft_sleep(1);
		mlx_do_sync(mlx_x->mlx);
	}
	else if (fps == 3)
	{
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_3, loc.j * 100, loc.i * 100);
		ft_sleep(1);
		mlx_do_sync(mlx_x->mlx);
	}
	else if (fps == 4)
	{
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_4, loc.j * 100, loc.i * 100);
		ft_sleep(1);
		mlx_do_sync(mlx_x->mlx);
	}
	else if (fps == 5)
	{
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_5, loc.j * 100, loc.i * 100);
		ft_sleep(1);
		mlx_do_sync(mlx_x->mlx);
	}
	else if (fps == 6)
	{
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_6, loc.j * 100, loc.i * 100);
		ft_sleep(1);
		mlx_do_sync(mlx_x->mlx);
	}
	else if (fps == 7)
	{
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_7, loc.j * 100, loc.i * 100);
		ft_sleep(1);
		mlx_do_sync(mlx_x->mlx);
	}
	else if (fps == 8)
	{
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_8, loc.j * 100, loc.i * 100);
		ft_sleep(1);
		mlx_do_sync(mlx_x->mlx);
	}
	else if (fps == 9)
	{
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_9, loc.j * 100, loc.i * 100);
		ft_sleep(1);
		mlx_do_sync(mlx_x->mlx);
	}
	else if (fps == 10)
	{
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_10, loc.j * 100, loc.i * 100);
		ft_sleep(1);
		mlx_do_sync(mlx_x->mlx);
	}
	fps++;
	if (fps > FPS)
		fps = 1;
	return (0);
}

int	enemy_animated(t_mlx_win *mlx_x)
{
	t_loc		loc;

	loc = fp(mlx_x->map, 'T', 'l');
	if (loc.i == -1)
		return (0);
	while (mlx_x->map[loc.i][loc.j + 1] != '1')
	{
		ft_sleep(1);
		mlx_x->map[loc.i][loc.j] = '0';
		mlx_x->map[loc.i][++loc.j] = 'T';
		ft_put_to_screen(mlx_x);
		mlx_do_sync(mlx_x->mlx);
	}
	// while (mlx_x->map[loc.i][loc.j - 1] != '1')
	// {
	// 	mlx_x->map[loc.i][loc.j--] = 0;
	// 	mlx_x->map[loc.i][loc.j] = 'T';
	// }
	// while (mlx_x->map[loc.i + 1][loc.j] != '1')
	// {
	// 	mlx_x->map[loc.i++][loc.j] = 0;
	// 	mlx_x->map[loc.i][loc.j] = 'T';
	// }
	// while (mlx_x->map[loc.i - 1][loc.j + 1] != '1')
	// {
	// 	mlx_x->map[loc.i--][loc.j] = 0;
	// 	mlx_x->map[loc.i][loc.j] = 'T';
	// }
	return (0);
}
