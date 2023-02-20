/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 05:32:04 by reben-ha          #+#    #+#             */
/*   Updated: 2023/02/20 13:21:43 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	midgard_hole(t_mlx_win *mlx_x)
{
	t_loc		loc;

	loc = fp(mlx_x->map, 'E', 'l');
	if (mlx_x->time_midgard <= 14 && fp(mlx_x->map, 'C', 'n').i == 1)
	{
		mlx_do_sync(mlx_x->mlx);
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_2, loc.j * 100, loc.i * 100);
	}
	else if (mlx_x->time_midgard <= 2)
	{
		mlx_do_sync(mlx_x->mlx);
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_1, loc.j * 100, loc.i * 100);
	}
	else if (mlx_x->time_midgard <= (2 * 2))
	{
		mlx_do_sync(mlx_x->mlx);
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_2, loc.j * 100, loc.i * 100);
	}
	else if (mlx_x->time_midgard <= (2 * 3))
	{
		mlx_do_sync(mlx_x->mlx);
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_3, loc.j * 100, loc.i * 100);
	}
	else if (mlx_x->time_midgard <= (2 * 4))
	{
		mlx_do_sync(mlx_x->mlx);
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_4, loc.j * 100, loc.i * 100);
	}
	else if (mlx_x->time_midgard <= (2 * 5))
	{
		mlx_do_sync(mlx_x->mlx);
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_5, loc.j * 100, loc.i * 100);
	}
	else if (mlx_x->time_midgard <= (2 * 6))
	{
		mlx_do_sync(mlx_x->mlx);
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_6, loc.j * 100, loc.i * 100);
	}
	else if (mlx_x->time_midgard <= (2 * 7))
	{
		mlx_do_sync(mlx_x->mlx);
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_7, loc.j * 100, loc.i * 100);
	}
	else if (mlx_x->time_midgard <= (2 * 8))
	{
		mlx_do_sync(mlx_x->mlx);
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_8, loc.j * 100, loc.i * 100);
	}
	else if (mlx_x->time_midgard <= (2 * 9))
	{
		mlx_do_sync(mlx_x->mlx);
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_9, loc.j * 100, loc.i * 100);
	}
	else if (mlx_x->time_midgard <= (2 * 10))
	{
		mlx_do_sync(mlx_x->mlx);
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_10, loc.j * 100, loc.i * 100);
		if (mlx_x->time_midgard == (2 * 10))
			mlx_x->time_midgard = 0;
	}
	mlx_x->time_midgard++;
}

void	enemy_animated(t_mlx_win *mlx_x)
{
	t_loc		loc;
	void		*img_enm;
	void		*img_flo;
	static		int i;

	loc = fp(mlx_x->map, 'T', 'l');
	if (loc.i == -1)
		return ;
	img_flo = mlx_x->img.floor;
	img_enm = mlx_x->img.enemy;
	mlx_x->time_enemy++;
	if (mlx_x->time_enemy <= mlx_x->frame)
		return ;
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
	if (mlx_x->time_enemy == (mlx_x->frame + 1))
		mlx_x->time_enemy = 0;
}

int	animation_sprite(t_mlx_win *mlx_x)
{
	t_loc		loc;
	static int	red;

	loc = fp(mlx_x->map, 'C', 'n');
	if (loc.i == -1 || loc.i == 1)
		midgard_hole(mlx_x);
	if ((loc.i == -1 || loc.i == 1 ) && red == 0)
	{
		mlx_x->frame = 5;
		mlx_x->time_enemy = 0;
		red = 1;
	}
	dprintf(2, "%d\n", mlx_x->time_enemy);
	enemy_animated(mlx_x);
	return (0);
}

/*
void	midgard_hole(t_mlx_win *mlx_x)
{
	t_loc		loc;
	int a = NUM_FRAMES / 10;
	loc = fp(mlx_x->map, 'E', 'l');
	// if (mlx_x->time_midgard <= 14 && fp(mlx_x->map, 'C', 'n').i == 1)
	// {
	// 	mlx_do_sync(mlx_x->mlx);
	// 	mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_2, loc.j * 100, loc.i * 100);
	// }
	if (mlx_x->frame >= 0 && mlx_x->frame < a)
	{
		mlx_do_sync(mlx_x->mlx);
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_1, loc.j * 100, loc.i * 100);
	}
	else if (mlx_x->frame >= a && mlx_x->frame < a * 2)
	{
		mlx_do_sync(mlx_x->mlx);
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_2, loc.j * 100, loc.i * 100);
	}
	else if (mlx_x->frame >= a * 2 && mlx_x->frame < a * 3)
	{
		mlx_do_sync(mlx_x->mlx);
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_3, loc.j * 100, loc.i * 100);
	}
	else if (mlx_x->frame >= a * 3 && mlx_x->frame < a * 4)
	{
		mlx_do_sync(mlx_x->mlx);
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_4, loc.j * 100, loc.i * 100);
	}
	else if (mlx_x->frame >= a * 4 && mlx_x->frame < a * 5)
	{
		mlx_do_sync(mlx_x->mlx);
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_5, loc.j * 100, loc.i * 100);
	}
	else if (mlx_x->frame >= a * 5 && mlx_x->frame < a * 6)
	{
		mlx_do_sync(mlx_x->mlx);
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_6, loc.j * 100, loc.i * 100);
	}
	else if (mlx_x->frame >= a * 6 && mlx_x->frame < a * 7)
	{
		mlx_do_sync(mlx_x->mlx);
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_7, loc.j * 100, loc.i * 100);
	}
	else if (mlx_x->frame >= a * 7 && mlx_x->frame < a * 8)
	{
		mlx_do_sync(mlx_x->mlx);
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_8, loc.j * 100, loc.i * 100);
	}
	else if (mlx_x->frame >= a * 8 && mlx_x->frame < a * 9)
	{
		mlx_do_sync(mlx_x->mlx);
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_9, loc.j * 100, loc.i * 100);
	}
	else if (mlx_x->frame >= a * 9 && mlx_x->frame < a * 10)
	{
		mlx_do_sync(mlx_x->mlx);
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_10, loc.j * 100, loc.i * 100);
	}
	// mlx_x->time_midgard++;
	return ;
}

void	enemy_animated(t_mlx_win *mlx_x)
{
	t_loc		loc;
	void		*img_enm;
	void		*img_flo;
	static int	i;

	loc = fp(mlx_x->map, 'T', 'l');
	if (loc.i == -1)
		return ;
	img_flo = mlx_x->img.floor;
	img_enm = mlx_x->img.enemy;
	// mlx_x->time_enemy++;
	// dprintf(2, "%d\n", mlx_x->time_enemy);
	// if (mlx_x->time_enemy <= 60)
	// 	return ; 
	int a = NUM_FRAMES / 2;
	if (mlx_x->map[loc.i][loc.j + 1] != '1' && i == 0)
	{
		if (mlx_x->frame >= 0 && mlx_x->frame > a)
		{
			if (mlx_x->map[loc.i][loc.j + 1] == 'P')
				exit(0);
			mlx_do_sync(mlx_x->mlx);
			mlx_x->map[loc.i][loc.j] = '0';
			mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, img_flo, (loc.j) * 100, loc.i * 100);
			mlx_x->map[loc.i][loc.j + 1] = 'T';
			mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, img_enm, (loc.j + 1) * 100, loc.i * 100);
			if (mlx_x->map[loc.i][loc.j + 2] == '1')
				i = 1;
		}
		else if (mlx_x->frame >= a && mlx_x->frame > a * 2)
		{
			// mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, img_flo, (loc.j + 1) * 100, loc.i * 100);
			mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, img_enm, (loc.j + 1) * 100, loc.i * 100);
		}
	}
	else if (mlx_x->map[loc.i][loc.j - 1] != '1' && i == 1)
	{
		if (mlx_x->frame >= 0 && mlx_x->frame > a)
		{
			if (mlx_x->map[loc.i][loc.j - 1] == 'P')
				exit(0);
			mlx_do_sync(mlx_x->mlx);
			mlx_x->map[loc.i][loc.j] = '0';
			mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, img_flo, (loc.j - 1) * 100, loc.i * 100);
			mlx_x->map[loc.i][loc.j - 1] = 'T';
			mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, img_enm, (loc.j - 1) * 100, loc.i * 100);
			if (mlx_x->map[loc.i][loc.j - 2] == '1')
				i = 0;
		}
		else if (mlx_x->frame >= a && mlx_x->frame > a * 2)
		{
			// mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, img_flo, loc.j * 100, loc.i * 100);
			mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, img_enm, loc.j * 100, loc.i * 100);
		}
	}
	// if (mlx_x->map[loc.i][loc.j + 1] != '1' && i == 0)
	// {
		
	// }
	// else if (mlx_x->map[loc.i][loc.j - 1] != '1' && i == 1)
	// {
	// 	if (mlx_x->map[loc.i][loc.j - 1] == 'P')
	// 		exit(0);
	// 	mlx_do_sync(mlx_x->mlx);
	// 	mlx_x->map[loc.i][loc.j] = '0';
	// 	mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, img_flo, loc.j * 100, loc.i * 100);
	// 	mlx_x->map[loc.i][loc.j - 1] = 'T';
	// 	mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, img_enm, (loc.j - 1) * 100, loc.i * 100);
	// 	if (mlx_x->map[loc.i][loc.j - 2] == '1')
	// 		i = 0;
	// }
	// if (mlx_x->time_enemy == 61)
	// 	mlx_x->time_enemy = 0;
	return ;
}

int animation_sprite (t_mlx_x *mlx_x)
{
	printf("sssc %d\n", mlx_x->frame);
	loc = fp(mlx_x->map, 'C', 'n');
	// if (loc.i == -1 || loc.i == 1)
	// 	midgard_hole(mlx_x);
	enemy_animated(mlx_x);
	mlx_x->frame++;
	if (mlx_x->frame == NUM_FRAMES)
		mlx_x->frame = 0;
	return (0);
}
*/