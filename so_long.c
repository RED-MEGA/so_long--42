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

// int	fun(int keycode, t_mlx_win *t_mlx);

int	main(int argc, char **argv)
{
	t_mlx_win	t_mlx;
	t_image		img;
	char		**map;
	int			len;
	int			width;
	int			height;
	char		*path_image = "texture/images/player/front.png";
	int			x;
	int			y;
	void		*img_ch;

	if (argc <= 1)
		return (ft_printf(2, "Error : Invalid argument\n"), 1);
	map = ft_input_manage(argv[1]);
	t_mlx.x = ft_strlen(map[0]);
	t_mlx.y = 0;
	while (map[t_mlx.y])
		t_mlx.y++;

	// Start in mlX

	t_mlx.mlx = mlx_init();

	t_mlx.mlx_win = mlx_new_window(t_mlx.mlx, t_mlx.x * 32, t_mlx.y * 32, "So_long REDMEGA-Edition");

	// Open Images


	
	img.player.front = mlx_xpm_file_to_image(t_mlx.mlx, "texture/sprites/player/front.xpm", &width, &height);
	ft_error_str(img.player.front, 1);
	img.player.back = mlx_xpm_file_to_image(t_mlx.mlx, "texture/sprites/player/back.xpm", &width, &height);
	ft_error_str(img.player.back, 1);
	img.player.right = mlx_xpm_file_to_image(t_mlx.mlx, "texture/sprites/player/right.xpm", &width, &height);
	ft_error_str(img.player.right, 1);
	img.player.left = mlx_xpm_file_to_image(t_mlx.mlx, "texture/sprites/player/left.xpm", &width, &height);
	ft_error_str(img.player.left, 1);
	img.floor = mlx_xpm_file_to_image(t_mlx.mlx, "texture/sprites/floor.xpm", &width, &height);
	ft_error_str(img.floor, 1);
	img.wall = mlx_xpm_file_to_image(t_mlx.mlx, "texture/sprites/wall.xpm", &width, &height);
	ft_error_str(img.wall, 1);
	img.coin = mlx_xpm_file_to_image(t_mlx.mlx, "texture/sprites/coin.xpm", &width, &height);
	ft_error_str(img.coin, 1);
	img.exit = mlx_xpm_file_to_image(t_mlx.mlx, "texture/sprites/exit.xpm", &width, &height);
	ft_error_str(img.exit, 1);

	// Display ...
	y = -1;
	printf("y = %d <> x = %d\n", t_mlx.y, t_mlx.x);
	while (++y < t_mlx.y)
	{
		x = -1;
		while (++x < t_mlx.x)
		{
			dprintf(2, "y = %d, x = %d >> %p %c\n", y, x, map[y], map[y][x]);
			if (map[y][x] == '0')
				img_ch = img.floor;
			else if (map[y][x] == '1')
				img_ch = img.wall;
			else if (map[y][x] == 'C')
				img_ch = img.coin;
			else if (map[y][x] == 'E')
				img_ch = img.exit;
			else if (map[y][x] == 'P')
				img_ch = img.player.front;
			mlx_put_image_to_window(t_mlx.mlx, t_mlx.mlx_win, img_ch, x * 32, y * 32);
		}
	}

	// Hook 
	// 126 keyup
	// 123 keyleft
	// 125 keydown
	// 125 keyright
	// W 13
	// A 0
	// D 2
 	// S 1
	// mlx_destroy_image(,);
	// t_mlx.x = fp(map, 'P', 'l').j;
	// t_mlx.y = fp(map, 'P', 'l').i;
	// mlx_hook(t_mlx.mlx_win, 2, 1L<<0, fun, &t_mlx);

	// Loop
	mlx_string_put(t_mlx.mlx, t_mlx.mlx_win, 0, 0, 0x00FF0000, "Hoooooot game");
	mlx_loop(t_mlx.mlx);
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




// input key
// apply function
// destroy image
// rerunder image