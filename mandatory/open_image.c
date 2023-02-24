/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 00:26:07 by reben-ha          #+#    #+#             */
/*   Updated: 2023/02/23 15:49:09 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	open_image_player(t_mlx_win *mlx_x)
{
	mlx_x->img.player.front = mlx_xpm_file_to_image(mlx_x->mlx,
			"texture/player/3-front.xpm", &(mlx_x->width), &(mlx_x->height));
	ft_error_str(mlx_x->img.player.front, 1);
	mlx_x->img.player.back = mlx_xpm_file_to_image(mlx_x->mlx,
			"texture/player/3-back.xpm", &(mlx_x->width), &(mlx_x->height));
	ft_error_str(mlx_x->img.player.back, 1);
	mlx_x->img.player.left = mlx_xpm_file_to_image(mlx_x->mlx,
			"texture/player/3-left.xpm", &(mlx_x->width), &(mlx_x->height));
	ft_error_str(mlx_x->img.player.left, 1);
	mlx_x->img.player.right = mlx_xpm_file_to_image(mlx_x->mlx,
			"texture/player/3-right.xpm", &(mlx_x->width), &(mlx_x->height));
	ft_error_str(mlx_x->img.player.right, 1);
}

static void	open_image_exit_part_one(t_mlx_win *mlx_x)
{
	mlx_x->img.exit = mlx_xpm_file_to_image(mlx_x->mlx, "texture/door/exit.xpm",
			&(mlx_x->width), &(mlx_x->height));
	ft_error_str(mlx_x->img.exit, 1);
	mlx_x->img.exit_2 = mlx_xpm_file_to_image(mlx_x->mlx,
			"texture/door/exit_2.xpm",
			&(mlx_x->width), &(mlx_x->height));
	ft_error_str(mlx_x->img.exit_2, 1);
	mlx_x->img.exit_hole.frame_1 = mlx_xpm_file_to_image(mlx_x->mlx,
			"texture/door/fps/1.xpm",
			&(mlx_x->width), &(mlx_x->height));
	ft_error_str(mlx_x->img.exit_hole.frame_1, 1);
	mlx_x->img.exit_hole.frame_2 = mlx_xpm_file_to_image(mlx_x->mlx,
			"texture/door/fps/2.xpm",
			&(mlx_x->width), &(mlx_x->height));
	ft_error_str(mlx_x->img.exit_hole.frame_2, 1);
}

static void	open_image_exit_part_two(t_mlx_win *mlx_x)
{
	mlx_x->img.exit_hole.frame_3 = mlx_xpm_file_to_image(mlx_x->mlx,
			"texture/door/fps/3.xpm",
			&(mlx_x->width), &(mlx_x->height));
	ft_error_str(mlx_x->img.exit_hole.frame_3, 1);
	mlx_x->img.exit_hole.frame_4 = mlx_xpm_file_to_image(mlx_x->mlx,
			"texture/door/fps/4.xpm",
			&(mlx_x->width), &(mlx_x->height));
	ft_error_str(mlx_x->img.exit_hole.frame_4, 1);
	mlx_x->img.exit_hole.frame_5 = mlx_xpm_file_to_image(mlx_x->mlx,
			"texture/door/fps/5.xpm",
			&(mlx_x->width), &(mlx_x->height));
	ft_error_str(mlx_x->img.exit_hole.frame_5, 1);
	mlx_x->img.exit_hole.frame_6 = mlx_xpm_file_to_image(mlx_x->mlx,
			"texture/door/fps/6.xpm",
			&(mlx_x->width), &(mlx_x->height));
	ft_error_str(mlx_x->img.exit_hole.frame_6, 1);
}

static void	open_image_exit_part_three(t_mlx_win *mlx_x)
{
	mlx_x->img.exit_hole.frame_7 = mlx_xpm_file_to_image(mlx_x->mlx,
			"texture/door/fps/7.xpm",
			&(mlx_x->width), &(mlx_x->height));
	ft_error_str(mlx_x->img.exit_hole.frame_7, 1);
	mlx_x->img.exit_hole.frame_8 = mlx_xpm_file_to_image(mlx_x->mlx,
			"texture/door/fps/8.xpm",
			&(mlx_x->width), &(mlx_x->height));
	ft_error_str(mlx_x->img.exit_hole.frame_8, 1);
	mlx_x->img.exit_hole.frame_9 = mlx_xpm_file_to_image(mlx_x->mlx,
			"texture/door/fps/9.xpm",
			&(mlx_x->width), &(mlx_x->height));
	ft_error_str(mlx_x->img.exit_hole.frame_9, 1);
	mlx_x->img.exit_hole.frame_10 = mlx_xpm_file_to_image(mlx_x->mlx,
			"texture/door/fps/10.xpm",
			&(mlx_x->width), &(mlx_x->height));
	ft_error_str(mlx_x->img.exit_hole.frame_10, 1);
}

void	ft_open_image(t_mlx_win *mlx_x)
{
	open_image_player(mlx_x);
	open_image_exit_part_one(mlx_x);
	open_image_exit_part_two(mlx_x);
	open_image_exit_part_three(mlx_x);
	mlx_x->img.floor = mlx_xpm_file_to_image(mlx_x->mlx,
			"texture/floor.xpm", &(mlx_x->width), &(mlx_x->height));
	ft_error_str(mlx_x->img.floor, 1);
	mlx_x->img.wall = mlx_xpm_file_to_image(mlx_x->mlx,
			"texture/wall.xpm", &(mlx_x->width), &(mlx_x->height));
	ft_error_str(mlx_x->img.wall, 1);
	mlx_x->img.coin = mlx_xpm_file_to_image(mlx_x->mlx,
			"texture/coin.xpm", &(mlx_x->width), &(mlx_x->height));
	ft_error_str(mlx_x->img.coin, 1);
	mlx_x->img.enemy = mlx_xpm_file_to_image(mlx_x->mlx,
			"texture/enemy_normal.xpm", &(mlx_x->width), &(mlx_x->height));
	ft_error_str(mlx_x->img.enemy, 1);
	mlx_x->img.enemy_angry = mlx_xpm_file_to_image(mlx_x->mlx,
			"texture/enemy_fight.xpm", &(mlx_x->width), &(mlx_x->height));
	ft_error_str(mlx_x->img.enemy_angry, 1);
}
