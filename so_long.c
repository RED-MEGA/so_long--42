/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:12:19 by reben-ha          #+#    #+#             */
/*   Updated: 2023/02/27 14:17:19 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	mlx_x.mlx = mlx_init();
	ft_open_image(&mlx_x);
	mlx_x.mlx_win = mlx_new_window(mlx_x.mlx, (mlx_x.x * mlx_x.width),
			(mlx_x.y * mlx_x.height), "So_long REDMEGA-Edition");
	ft_select_img(&mlx_x, "front");
	ft_put_to_screen(&mlx_x);
	mlx_put_image_to_window(mlx_x.mlx, mlx_x.mlx_win, mlx_x.img.start,
		(mlx_x.width * mlx_x.x) / 2 - 400, (mlx_x.height * mlx_x.y) / 2 - 100);
	mlx_key_hook(mlx_x.mlx_win, apply_key, &mlx_x);
	mlx_hook(mlx_x.mlx_win, DESTROYNOTIFY, 0, exit_window, &mlx_x);
	mlx_loop_hook(mlx_x.mlx, animation_sprite, &mlx_x);
	mlx_loop(mlx_x.mlx);
}
