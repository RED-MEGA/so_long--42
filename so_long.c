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

int	midgard_hole(t_mlx_win *mlx_x)
{
	t_loc		loc;
	static int	fps;

	loc = fp(mlx_x->map, 'E', 'l');
	dprintf(2, "%d = %d\n", loc.i , loc.j);
	if (fps == 1)
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_1, loc.j * 100, loc.i * 100);
	else if (fps == 2)
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_2, loc.j * 100, loc.i * 100);
	else if (fps == 3)
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_3, loc.j * 100, loc.i * 100);
	else if (fps == 4)
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_4, loc.j * 100, loc.i * 100);
	else if (fps == 5)
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_5, loc.j * 100, loc.i * 100);
	else if (fps == 6)
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_6, loc.j * 100, loc.i * 100);
	else if (fps == 7)
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_7, loc.j * 100, loc.i * 100);
	else if (fps == 8)
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_8, loc.j * 100, loc.i * 100);
	else if (fps == 9)
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_9, loc.j * 100, loc.i * 100);
	else if (fps == 10)
		mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, mlx_x->img.exit_hole.frame_10, loc.j * 100, loc.i * 100);
	fps++;
	if (fps > FPS)
		fps = 1;
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx_win	mlx_x;

	if (argc <= 1)
		return (ft_printf(2, "Error : Invalid argument\n"), 1);
	mlx_x.map = ft_input_manage(argv[1]);
	mlx_x.moves = 0;
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
	dprintf(2, "%d = %d\n", mlx_x.width, mlx_x.height);
	ft_put_to_screen(&mlx_x);
	// game start
	mlx_hook(mlx_x.mlx_win, KEYPRESS, 0, apply_key, &mlx_x);
	mlx_hook(mlx_x.mlx_win, DESTROYNOTIFY, 0, exit_window, 0);
	// Loop
	mlx_loop_hook(mlx_x.mlx, midgard_hole, &mlx_x);
	mlx_loop(mlx_x.mlx);
}
