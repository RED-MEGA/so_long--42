/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 05:32:04 by reben-ha          #+#    #+#             */
/*   Updated: 2023/02/20 11:08:47 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	midgard_hole(t_mlx_win *mlx_x)
{
	t_loc		loc;

	loc = fp(mlx_x->map, 'E', 'l');
	if (mlx_x->time <= 14 && fp(mlx_x->map, 'C', 'n').i == 1)
	{
		mlx_do_sync(mlx_x->mlx);
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_2, loc.j * 100, loc.i * 100);
	}
	else if (mlx_x->time <= 2)
	{
		mlx_do_sync(mlx_x->mlx);
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_1, loc.j * 100, loc.i * 100);
	}
	else if (mlx_x->time <= (2 * 2))
	{
		mlx_do_sync(mlx_x->mlx);
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_2, loc.j * 100, loc.i * 100);
	}
	else if (mlx_x->time <= (2 * 3))
	{
		mlx_do_sync(mlx_x->mlx);
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_3, loc.j * 100, loc.i * 100);
	}
	else if (mlx_x->time <= (2 * 4))
	{
		mlx_do_sync(mlx_x->mlx);
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_4, loc.j * 100, loc.i * 100);
	}
	else if (mlx_x->time <= (2 * 5))
	{
		mlx_do_sync(mlx_x->mlx);
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_5, loc.j * 100, loc.i * 100);
	}
	else if (mlx_x->time <= (2 * 6))
	{
		mlx_do_sync(mlx_x->mlx);
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_6, loc.j * 100, loc.i * 100);
	}
	else if (mlx_x->time <= (2 * 7))
	{
		mlx_do_sync(mlx_x->mlx);
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_7, loc.j * 100, loc.i * 100);
	}
	else if (mlx_x->time <= (2 * 8))
	{
		mlx_do_sync(mlx_x->mlx);
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_8, loc.j * 100, loc.i * 100);
	}
	else if (mlx_x->time <= (2 * 9))
	{
		mlx_do_sync(mlx_x->mlx);
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_9, loc.j * 100, loc.i * 100);
	}
	else if (mlx_x->time <= (2 * 10))
	{
		mlx_do_sync(mlx_x->mlx);
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_10, loc.j * 100, loc.i * 100);
		if (mlx_x->time == (2 * 10))
			mlx_x->time = 0;
	}
	mlx_x->time++;
	return (0);
}

int	enemy_animated(t_mlx_win *mlx_x)
{
	t_loc		loc;
	void		*img_enm;
	void		*img_flo;
	static int	i;

	loc = fp(mlx_x->map, 'T', 'l');
	if (loc.i == -1)
		return (0);
	img_flo = mlx_x->img.floor;
	img_enm = mlx_x->img.enemy;
	if (mlx_x->map[loc.i][loc.j + 1] != '1' && i == 0)
	{
		if (mlx_x->map[loc.i][loc.j + 1] == 'P')
			exit(0);
		mlx_do_sync(mlx_x->mlx);
		mlx_x->map[loc.i][loc.j] = '0';
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, img_flo, loc.j * 100, loc.i * 100);
		mlx_x->map[loc.i][loc.j + 1] = 'T';
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, img_enm, (loc.j + 1) * 100, loc.i * 100);
		if (mlx_x->map[loc.i][loc.j + 2] == '1')
			i = 1;
	}
	else if (mlx_x->map[loc.i][loc.j - 1] != '1' && i == 1)
	{
		if (mlx_x->map[loc.i][loc.j - 1] == 'P')
			exit(0);
		mlx_do_sync(mlx_x->mlx);
		mlx_x->map[loc.i][loc.j] = '0';
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, img_flo, loc.j * 100, loc.i * 100);
		mlx_x->map[loc.i][loc.j - 1] = 'T';
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, img_enm, (loc.j - 1) * 100, loc.i * 100);
		if (mlx_x->map[loc.i][loc.j - 2] == '1')
			i = 0;
	}
	return (0);
}

int	animation_sprite(t_mlx_win *mlx_x)
{
	t_loc		loc;

	loc = fp(mlx_x->map, 'C', 'n');
	if (loc.i == -1 || loc.i == 1)
		midgard_hole(mlx_x);
	enemy_animated(mlx_x);
	return (0);
}
