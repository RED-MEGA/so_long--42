/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:12:19 by reben-ha          #+#    #+#             */
/*   Updated: 2023/02/24 17:00:33 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	ft_error(int status, int code)
{
	if (status == FAIL)
		return (perror("Error "), exit(code));
}

void	ft_error_str(void *status, int code)
{
	if (status == NULL)
		return (perror("Error "), exit(code));
}

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

int	main(int argc, char **argv)
{
	t_mlx_win	mlx_x;

	if (argc <= 1)
		return (ft_printf(2, "Error : Invalid argument\n"), 1);
	mlx_x.frame = 2500;
	mlx_x.map = ft_input_manage(argv[1]);
	mlx_x.moves = 0;
	mlx_x.time_enemy = 0;
	mlx_x.time_midgard = 0;
	mlx_x.y = 0;
	mlx_x.x = ft_strlen(mlx_x.map[0]);
	while (mlx_x.map[mlx_x.y])
		mlx_x.y++;
	// Start in mlX
	mlx_x.mlx = mlx_init();
	// Open Images
	ft_open_image(&mlx_x);
	// Open Window
	mlx_x.mlx_win = mlx_new_window(mlx_x.mlx, (mlx_x.x * mlx_x.width),
			(mlx_x.y * mlx_x.height), "So_long REDMEGA-Edition");
	// Display ...
	ft_select_img(&mlx_x, "front");
	ft_put_to_screen(&mlx_x);
	mlx_put_image_to_window(mlx_x.mlx, mlx_x.mlx_win,
		mlx_x.img.start, (mlx_x.width * mlx_x.x) / 2 - 400, (mlx_x.height * mlx_x.y) / 2 - 100);
	// game start
	mlx_hook(mlx_x.mlx_win, KEYPRESS, 0, apply_key, &mlx_x);
	mlx_hook(mlx_x.mlx_win, DESTROYNOTIFY, 0, exit_window, &mlx_x);
	// Loop
	mlx_loop_hook(mlx_x.mlx, animation_sprite, &mlx_x);
	mlx_loop(mlx_x.mlx);
}
