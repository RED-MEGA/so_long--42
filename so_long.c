/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:26:08 by reben-ha          #+#    #+#             */
/*   Updated: 2023/02/13 01:50:17 by reben-ha         ###   ########.fr       */
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

void    ft_error(int status, int code)
{
	if (status == FAIL)
		return (perror("Error "), exit(code));
}

int	main(int argc, char **argv)
{
	t_mlx_win	img;
	char		**map;
	int			len;
	int			width;
	int			height;
	char		*path_image = "kars.xpm";
	int			x;
	int			y;

	if (argc <= 1)
		return (ft_printf(2, "Error : Invalid argument\n"), 1);
	map = ft_input_manage(argv[1]);
	img.x = ft_strlen(map[0]);
	img.y = 0;
	while (map[img.y])
		img.y++;

	// Start in mlX

	img.mlx = mlx_init();

	img.mlx_win = mlx_new_window(img.mlx, img.x * 70, img.y * 70, "So_long REDMEGA-Edition");

	img.img = mlx_xpm_file_to_image(img.mlx, path_image, &width, &height);

	x = -1;
	y = 0;
	while (++x < img.x)
	{
		mlx_string_put(img.mlx, img.mlx_win, 0, 0, 0x00FF0000, ft_strjoin_gnl(ft_strjoin(ft_itoa(width), " "), ft_itoa(height)));
		mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, x * 70, y);
	}
	mlx_loop(img.mlx);
}
