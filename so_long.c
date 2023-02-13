#include "so_long.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void    ft_error(int status, int code)
{
	if (status == FAIL)
		return (perror("Error "), exit(code));
}

void    ft_error_str(void *status, int code)
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

	y = -1;
	printf("y = %d <> x = %d\n", mlx_x->y, mlx_x->x);
	while (++y < mlx_x->y)
	{
		x = -1;
		while (++x < mlx_x->x)
		{
			dprintf(2, "y = %d, x = %d >> %p %c\n", y, x, map[y], map[y][x]);
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

// int	fun(int keycode, t_mlx_win *t_mlx)
// {
// 	printf("%d\n", keycode);
// 	if (keycode == 126)
// 	{
// 		t_mlx.x += ;
// 		t_mlx.y += ;
// 	}
// }

int	main(int argc, char **argv)
{
	t_mlx_win	mlx_x;
	t_image		img;
	char		**map;
	int			len;
	int			width;
	int			height;

	if (argc <= 1)
		return (ft_printf(2, "Error : Invalid argument\n"), 1);
	map = ft_input_manage(argv[1]);
	mlx_x.x = ft_strlen(map[0]);
	mlx_x.y = 0;
	while (map[mlx_x.y])
		mlx_x.y++;

	// Start in mlX

	mlx_x.mlx = mlx_init();

	// Open Images


	ft_open_image(&img, &mlx_x, &width, &height);

	// Open Windows in Macos HHHHH

	mlx_x.mlx_win = mlx_new_window(mlx_x.mlx, mlx_x.x * width, mlx_x.y * height, "So_long REDMEGA-Edition");


	// Display ...
	ft_put_to_screen(map, &img, &mlx_x, width, height);



	// mlx_destroy_image(,);
	// mlx_x.x = fp(map, 'P', 'l').j;
	// mlx_x.y = fp(map, 'P', 'l').i;
	// mlx_hook(mlx_x.mlx_win, 2, 1L<<0, fun, &mlx_x);

	// Loop
	mlx_string_put(mlx_x.mlx, mlx_x.mlx_win, 0, 0, 0x00FF0000, "Hoooooot game");
	mlx_loop(mlx_x.mlx);
}





// input key
// apply function
// destroy image
// rerunder image