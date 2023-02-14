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

void	ft_open_image(t_image *img, t_mlx_win *mlx_x, int *width, int *height)
{
	img->player.front = mlx_xpm_file_to_image(mlx_x->mlx, "texture/sprites/player/front.xpm", width, height);
	ft_error_str(img->player.front, 1);
	img->player.back = mlx_xpm_file_to_image(mlx_x->mlx, "texture/sprites/player/back.xpm", width, height);
	ft_error_str(img->player.back, 1);
	img->player.right = mlx_xpm_file_to_image(mlx_x->mlx, "texture/sprites/player/right.xpm", width, height);
	ft_error_str(img->player.right, 1);
	img->player.left = mlx_xpm_file_to_image(mlx_x->mlx, "texture/sprites/player/left.xpm", width, height);
	ft_error_str(img->player.left, 1);
	img->floor = mlx_xpm_file_to_image(mlx_x->mlx, "texture/sprites/floor.xpm", width, height);
	ft_error_str(img->floor, 1);
	img->wall = mlx_xpm_file_to_image(mlx_x->mlx, "texture/sprites/wall.xpm", width, height);
	ft_error_str(img->wall, 1);
	img->coin = mlx_xpm_file_to_image(mlx_x->mlx, "texture/sprites/coin.xpm", width, height);
	ft_error_str(img->coin, 1);
	img->exit = mlx_xpm_file_to_image(mlx_x->mlx, "texture/sprites/exit.xpm", width, height);
	ft_error_str(img->exit, 1);
}

void	ft_put_to_screen(char **map, t_image *img, t_mlx_win *mlx_x, int width, int height)
{
	void	*img_ch;
	int		x;
	int		y;

	// mlx_clear_window(, );
	y = -1;
	while (++y < mlx_x->y)
	{
		x = -1;
		while (++x < mlx_x->x)
		{
			if (map[y][x] == '0')
				img_ch = img->floor;
			else if (map[y][x] == '1')
				img_ch = img->wall;
			else if (map[y][x] == 'C')
				img_ch = img->coin;
			else if (map[y][x] == 'E')
				img_ch = img->exit;
			else if (map[y][x] == 'P')
				img_ch = img->player.front;
			mlx_put_image_to_window(mlx_x->mlx, mlx_x->mlx_win, img_ch, x * width, y * height);
		}
	}
}

int	apply_key(int keycode, t_mlx_win *mlx_x)
{
	t_loc	loc;

	dprintf(2, "keycode = %d\n", keycode);
	if (keycode == 53)
		exit(0);
	loc = fp(mlx_x->map, 'P', 'l');
	if (keycode == 126 || keycode == 13)
	{
		if (mlx_x->map[loc.i - 1][loc.j] == '1')
			return (-1);
		if (mlx_x->map[loc.i - 1][loc.j] == 'E' && fp(mlx_x->map, 'C', 'l').i == FAIL)
			exit(1);
		else if (mlx_x->map[loc.i - 1][loc.j] == 'E')
			return (-1);
		mlx_x->map[loc.i - 1][loc.j] = 'P';
		mlx_x->map[loc.i][loc.j] = '0';
		mlx_x->moves += 1;
	}
	else if (keycode == 123 || keycode == 0)
	{
		if (mlx_x->map[loc.i][loc.j - 1] == '1')
			return (-1);
		if (mlx_x->map[loc.i][loc.j - 1] == 'E' && fp(mlx_x->map, 'C', 'l').i == FAIL)
			exit(1);
		else if (mlx_x->map[loc.i][loc.j - 1] == 'E')
			return (-1);
		mlx_x->map[loc.i][loc.j - 1] = 'P';
		mlx_x->map[loc.i][loc.j] = '0';
		mlx_x->moves += 1;
	}
	else if (keycode == 125 || keycode == 1)
	{
		if (mlx_x->map[loc.i + 1][loc.j] == '1')
			return (-1);
		if (mlx_x->map[loc.i + 1][loc.j] == 'E' && fp(mlx_x->map, 'C', 'l').i == FAIL)
			exit(1);
		else if (mlx_x->map[loc.i + 1][loc.j] == 'E')
			return (-1);
		mlx_x->map[loc.i + 1][loc.j] = 'P';
		mlx_x->map[loc.i][loc.j] = '0';
		mlx_x->moves += 1;
	}
	else if (keycode == 124 || keycode == 2)
	{
		if (mlx_x->map[loc.i][loc.j + 1] == '1')
			return (-1);
		if (mlx_x->map[loc.i][loc.j + 1] == 'E' && fp(mlx_x->map, 'C', 'l').i == FAIL)
			exit(1);
		else if (mlx_x->map[loc.i][loc.j + 1] == 'E')
			return (-1);
		mlx_x->map[loc.i][loc.j + 1] = 'P';
		mlx_x->map[loc.i][loc.j] = '0';
		mlx_x->moves += 1;
	}
	ft_put_to_screen(mlx_x->map, &mlx_x->img, mlx_x, mlx_x->width, mlx_x->height);
	mlx_string_put(mlx_x->mlx, mlx_x->mlx_win, 32, 32, 0xFFFFFF, ft_itoa(mlx_x->moves));
	return (0);
}

int	exit_window(void *param)
{
	(void)param;
	exit(0);
}

int	main(int argc, char **argv)
{
	t_mlx_win	mlx_x;
	int			width;
	int			height;

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
	ft_open_image(&mlx_x.img, &mlx_x, &width, &height);
	// Open Window
	mlx_x.mlx_win = mlx_new_window(mlx_x.mlx, mlx_x.x * width, mlx_x.y * height, "So_long REDMEGA-Edition");
	// Display ...
	ft_put_to_screen(mlx_x.map, &mlx_x.img, &mlx_x, width, height);
	// game start
	mlx_x.height = height;
	mlx_x.width = width;
	mlx_hook(mlx_x.mlx_win, KEYPRESS, 0, apply_key, &mlx_x);
	mlx_hook(mlx_x.mlx_win, DESTROYNOTIFY, 0, exit_window, 0);
	// Loop
	mlx_string_put(mlx_x.mlx, mlx_x.mlx_win, 0, 0, 0x00FF0000, "Hoooooot game");
	mlx_loop(mlx_x.mlx);
}
