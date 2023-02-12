/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:26:08 by reben-ha          #+#    #+#             */
/*   Updated: 2023/02/12 22:00:56 by reben-ha         ###   ########.fr       */
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

	if (argc <= 1)
		return (ft_printf(2, "Error : Invalid argument\n"), 1);
	map = ft_input_manage(argv[1]);
	img.x = ft_strlen(map[0]);
	img.y = 0;
	while (map[img.y])
		img.y++;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, img.x * 50, img.y * 50, "So_long REDMEGA-Edition");
	
	// img = mlx_xpm_to_image(mlx, ); //
	
	// mlx_put_image_to_window(mlx, mlx_win, img, );

	mlx_loop(img.mlx);
	// system("leaks so_long");
}
