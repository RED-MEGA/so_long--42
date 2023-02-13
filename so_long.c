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

int	main(int argc, char **argv)
{
	t_mlx_win	t_mlx;
	t_image		img;
	char		**map;
	int			len;
	int			width;
	int			height;
	char		*path_image = "kars.xpm";
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

	t_mlx.mlx_win = mlx_new_window(t_mlx.mlx, t_mlx.x * 70, t_mlx.y * 70, "So_long REDMEGA-Edition");

	// Open Images
	img.player.front = mlx_xpm_file_to_image(t_mlx.mlx, t_mlx.mlx_win, &width, &height);
	ft_error_str(img.player.front, 1);
	img.player.back = mlx_xpm_file_to_image(t_mlx.mlx, t_mlx.mlx_win, &width, &height);
	ft_error_str(img.player.back, 1);
	img.player.right = mlx_xpm_file_to_image(t_mlx.mlx, t_mlx.mlx_win, &width, &height);
	ft_error_str(img.player.right, 1);
	img.player.left = mlx_xpm_file_to_image(t_mlx.mlx, t_mlx.mlx_win, &width, &height);
	ft_error_str(img.player.left, 1);
	img.floor = mlx_xpm_file_to_image(t_mlx.mlx, t_mlx.mlx_win, &width, &height);
	ft_error_str(img.floor, 1);
	img.wall = mlx_xpm_file_to_image(t_mlx.mlx, t_mlx.mlx_win, &width, &height);
	ft_error_str(img.wall, 1);
	img.coin = mlx_xpm_file_to_image(t_mlx.mlx, t_mlx.mlx_win, &width, &height);
	ft_error_str(img.coin, 1);
	img.exit = mlx_xpm_file_to_image(t_mlx.mlx, t_mlx.mlx_win, &width, &height);
	ft_error_str(img.exit, 1);

	// Display ...
	x = -1;
	y = -1;
	while (++x <= t_mlx.y)
	{
		while (++y <= t_mlx.x)
		{
			
			map[x][y];
			mlx_put_image_to_window(t_mlx.mlx, t_mlx.mlx_win, img_ch, x, y);
		}
	}
	




	mlx_string_put(t_mlx.mlx, t_mlx.mlx_win, 0, 0, 0x00FF0000, ft_strjoin_gnl(ft_strjoin(ft_itoa(width), " "), ft_itoa(height)));
	mlx_loop(t_mlx.mlx);
}
