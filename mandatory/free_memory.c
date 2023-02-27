/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:16:46 by reben-ha          #+#    #+#             */
/*   Updated: 2023/02/27 14:17:13 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	ft_destroy(t_mlx_win *mlx_x)
{
	mlx_destroy_image(mlx_x->mlx, mlx_x->img.coin);
	mlx_destroy_image(mlx_x->mlx, mlx_x->img.enemy);
	mlx_destroy_image(mlx_x->mlx, mlx_x->img.enemy_angry);
	mlx_destroy_image(mlx_x->mlx, mlx_x->img.exit);
	mlx_destroy_image(mlx_x->mlx, mlx_x->img.exit_2);
	mlx_destroy_image(mlx_x->mlx, mlx_x->img.floor);
	mlx_destroy_image(mlx_x->mlx, mlx_x->img.wall);
	mlx_destroy_image(mlx_x->mlx, mlx_x->img.player.back);
	mlx_destroy_image(mlx_x->mlx, mlx_x->img.player.front);
	mlx_destroy_image(mlx_x->mlx, mlx_x->img.player.left);
	mlx_destroy_image(mlx_x->mlx, mlx_x->img.player.right);
	mlx_destroy_image(mlx_x->mlx, mlx_x->img.exit_hole.frame_1);
	mlx_destroy_image(mlx_x->mlx, mlx_x->img.exit_hole.frame_2);
	mlx_destroy_image(mlx_x->mlx, mlx_x->img.exit_hole.frame_3);
	mlx_destroy_image(mlx_x->mlx, mlx_x->img.exit_hole.frame_4);
	mlx_destroy_image(mlx_x->mlx, mlx_x->img.exit_hole.frame_5);
	mlx_destroy_image(mlx_x->mlx, mlx_x->img.exit_hole.frame_6);
	mlx_destroy_image(mlx_x->mlx, mlx_x->img.exit_hole.frame_7);
	mlx_destroy_image(mlx_x->mlx, mlx_x->img.exit_hole.frame_8);
	mlx_destroy_image(mlx_x->mlx, mlx_x->img.exit_hole.frame_9);
	mlx_destroy_image(mlx_x->mlx, mlx_x->img.exit_hole.frame_10);
}
