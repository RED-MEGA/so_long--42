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
	{
		mlx_x->img.player.main.frame_3 = mlx_x->img.player.front.frame_3;
		mlx_x->img.player.main.frame_2 = mlx_x->img.player.front.frame_2;
		mlx_x->img.player.main.frame_1 = mlx_x->img.player.front.frame_1;
	}
	else if (ft_strncmp(option, "back", 4) == 0)
	{
		mlx_x->img.player.main.frame_3 = mlx_x->img.player.back.frame_3;
		mlx_x->img.player.main.frame_2 = mlx_x->img.player.back.frame_2;
		mlx_x->img.player.main.frame_1 = mlx_x->img.player.back.frame_1;
	}
	else if (ft_strncmp(option, "left", 4) == 0)
	{
		mlx_x->img.player.main.frame_3 = mlx_x->img.player.left.frame_3;
		mlx_x->img.player.main.frame_2 = mlx_x->img.player.left.frame_2;
		mlx_x->img.player.main.frame_1 = mlx_x->img.player.left.frame_1;
	}
	else if (ft_strncmp(option, "right", 5) == 0)
	{
		mlx_x->img.player.main.frame_3 = mlx_x->img.player.right.frame_3;
		mlx_x->img.player.main.frame_2 = mlx_x->img.player.right.frame_2;
		mlx_x->img.player.main.frame_1 = mlx_x->img.player.right.frame_1;
	}
	else
		return ;
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
	mlx_x.mlx_win = mlx_new_window(mlx_x.mlx, (mlx_x.x * mlx_x.width), (mlx_x.y * mlx_x.height), "So_long REDMEGA-Edition");
	// Display ...
	mlx_x.img.player.main.frame_3 = mlx_x.img.player.back.frame_3;
	mlx_x.img.player.main.frame_2 = mlx_x.img.player.back.frame_2;
	mlx_x.img.player.main.frame_1 = mlx_x.img.player.back.frame_1;
	ft_put_to_screen(&mlx_x);

	// game start
	mlx_hook(mlx_x.mlx_win, KEYPRESS, 0, apply_key, &mlx_x);
	mlx_hook(mlx_x.mlx_win, DESTROYNOTIFY, 0, exit_window, 0);
	// Loop
	mlx_loop_hook(mlx_x.mlx, animation_sprite, &mlx_x);
	mlx_loop(mlx_x.mlx);
}
