/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 00:26:07 by reben-ha          #+#    #+#             */
/*   Updated: 2023/02/17 00:37:47 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_open_image(t_mlx_win *mlx_x)
{
	mlx_x->img.player.front = mlx_xpm_file_to_image(mlx_x->mlx, "texture/player/3-front.xpm", &(mlx_x->width), &(mlx_x->height));
	ft_error_str(mlx_x->img.player.front, 1);
	mlx_x->img.player.back = mlx_xpm_file_to_image(mlx_x->mlx, "texture/player/3-back.xpm", &(mlx_x->width), &(mlx_x->height));
	ft_error_str(mlx_x->img.player.back, 1);
	mlx_x->img.player.right = mlx_xpm_file_to_image(mlx_x->mlx, "texture/player/3-right.xpm", &(mlx_x->width), &(mlx_x->height));
	ft_error_str(mlx_x->img.player.right, 1);
	mlx_x->img.player.left = mlx_xpm_file_to_image(mlx_x->mlx, "texture/player/3-left.xpm", &(mlx_x->width), &(mlx_x->height));
	ft_error_str(mlx_x->img.player.left, 1);
	mlx_x->img.floor = mlx_xpm_file_to_image(mlx_x->mlx, "texture/floor.xpm", &(mlx_x->width), &(mlx_x->height));
	ft_error_str(mlx_x->img.floor, 1);
	mlx_x->img.wall = mlx_xpm_file_to_image(mlx_x->mlx, "texture/wall.xpm", &(mlx_x->width), &(mlx_x->height));
	ft_error_str(mlx_x->img.wall, 1);
	mlx_x->img.coin = mlx_xpm_file_to_image(mlx_x->mlx, "texture/coin.xpm", &(mlx_x->width), &(mlx_x->height));
	ft_error_str(mlx_x->img.coin, 1);
	mlx_x->img.exit = mlx_xpm_file_to_image(mlx_x->mlx, "texture/door/exit.xpm", &(mlx_x->width), &(mlx_x->height));
	ft_error_str(mlx_x->img.exit, 1);
	mlx_x->img.enemy = mlx_xpm_file_to_image(mlx_x->mlx, "texture/enemy_normal.xpm", &(mlx_x->width), &(mlx_x->height));
	ft_error_str(mlx_x->img.enemy, 1);
}
