/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 05:32:04 by reben-ha          #+#    #+#             */
/*   Updated: 2023/02/24 21:48:24 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	select_img_hole(t_mlx_win *mlx_x, char *img_ch, t_loc loc)
{
	mlx_do_sync(mlx_x->mlx);
	mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, img_ch,
		loc.j * 100, loc.i * 100);
}

void	midgard_hole(t_mlx_win *mlx_x, t_loc loc)
{
	if (mlx_x->time_midgard <= 14 && fp(mlx_x->map, 'C', 'n').i == 1)
		select_img_hole(mlx_x, mlx_x->img.exit_2, loc);
	else if (mlx_x->time_midgard <= 2)
		select_img_hole(mlx_x, mlx_x->img.exit_hole.frame_1, loc);
	else if (mlx_x->time_midgard <= (2 * 2))
		select_img_hole(mlx_x, mlx_x->img.exit_hole.frame_2, loc);
	else if (mlx_x->time_midgard <= (2 * 3))
		select_img_hole(mlx_x, mlx_x->img.exit_hole.frame_3, loc);
	else if (mlx_x->time_midgard <= (2 * 4))
		select_img_hole(mlx_x, mlx_x->img.exit_hole.frame_4, loc);
	else if (mlx_x->time_midgard <= (2 * 5))
		select_img_hole(mlx_x, mlx_x->img.exit_hole.frame_5, loc);
	else if (mlx_x->time_midgard <= (2 * 6))
		select_img_hole(mlx_x, mlx_x->img.exit_hole.frame_6, loc);
	else if (mlx_x->time_midgard <= (2 * 7))
		select_img_hole(mlx_x, mlx_x->img.exit_hole.frame_7, loc);
	else if (mlx_x->time_midgard <= (2 * 8))
		select_img_hole(mlx_x, mlx_x->img.exit_hole.frame_8, loc);
	else if (mlx_x->time_midgard <= (2 * 9))
		select_img_hole(mlx_x, mlx_x->img.exit_hole.frame_9, loc);
	else if (mlx_x->time_midgard <= (2 * 10))
		select_img_hole(mlx_x, mlx_x->img.exit_hole.frame_10, loc);
	if (mlx_x->time_midgard == (2 * 10))
		mlx_x->time_midgard = 0;
	mlx_x->time_midgard++;
}

static void	part_enemy_animated(t_mlx_win *mlx_x, t_loc loc,
			int new_x, char *img_enm)
{
	if (mlx_x->map[loc.i][new_x] == 'P')
		return (ft_printf(1, "\033[1;31mYOU ARE DEAD\n"),
			ft_destroy(mlx_x), exit(0));
	mlx_do_sync(mlx_x->mlx);
	mlx_x->map[loc.i][loc.j] = '0';
	mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.floor,
		loc.j * 100, loc.i * 100);
	mlx_x->map[loc.i][new_x] = 'T';
	mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, img_enm,
		new_x * 100, loc.i * 100);
}

void	enemy_animated(t_mlx_win *mlx_x, t_loc loc)
{
	void		*img_enm;
	static int	i;

	if (loc.i == -1)
		return ;
	if (i == 0)
		img_enm = mlx_x->img.enemy_angry;
	else if (i == 1)
		img_enm = mlx_x->img.enemy;
	mlx_x->time_enemy++;
	if (mlx_x->time_enemy <= mlx_x->frame)
		return ;
	if (mlx_x->map[loc.i][loc.j + 1] != '1' && i == 0)
	{
		part_enemy_animated(mlx_x, loc, (loc.j + 1), img_enm);
		if (mlx_x->map[loc.i][loc.j + 2] == '1')
			i = 1;
	}
	else if (mlx_x->map[loc.i][loc.j - 1] != '1' && i == 1)
	{
		part_enemy_animated(mlx_x, loc, (loc.j - 1), img_enm);
		if (mlx_x->map[loc.i][loc.j - 2] == '1')
			i = 0;
	}
	if (mlx_x->time_enemy == (mlx_x->frame + 1))
		mlx_x->time_enemy = 0;
}

int	animation_sprite(t_mlx_win *mlx_x)
{
	t_loc		loc;
	static int	red;

	loc = fp(mlx_x->map, 'C', 'n');
	if (loc.i == -1 || loc.i == 1)
		midgard_hole(mlx_x, fp(mlx_x->map, 'E', 'l'));
	if ((loc.i == -1 || loc.i == 1) && red == 0)
	{
		mlx_x->frame = 5;
		mlx_x->time_enemy = 0;
		red = 1;
	}
	enemy_animated(mlx_x, fp(mlx_x->map, 'T', 'l'));
	return (0);
}
