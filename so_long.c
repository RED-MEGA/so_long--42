/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:26:08 by reben-ha          #+#    #+#             */
/*   Updated: 2023/02/13 00:29:09 by reben-ha         ###   ########.fr       */
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
	t_image	img;
	char	**map;
	int		len;
	int		img_width;
	int		img_height;
	char	*path_image = "wall.xpm";

	if (argc <= 1)
		return (ft_printf(2, "Error : Invalid argument\n"), 1);
	map = ft_input_manage(argv[1]);
	img.x = ft_strlen(map[0]);
	img.y = 0;
	while (map[img.y])
		img.y++;
	img.x = img.x;
	img.y = img.y;
	// Start in mlX

	img.mlx = mlx_init();

	img.mlx_win = mlx_new_window(img.mlx, img.x * 50, img.y * 50, "So_long REDMEGA-Edition");

	img.img = mlx_xpm_file_to_image(img.mlx, path_image, &img_width, &img_height);

	int i, j;
	i = -1;
	j = -1;
	// while (++i < img.x * 50)
	// {
	// 	while (++j < img.y * 50)
	// 	{
			mlx_string_put(img.mlx, img.mlx_win, 0, 0, 0x00FF0000, ft_strjoin_gnl(ft_strjoin(ft_itoa(img_width), " "), ft_itoa(img_height)));
			mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 50, 50);
			// mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, i + 50, j + 50);
	// 	}
	// }

	mlx_loop(img.mlx);
}
