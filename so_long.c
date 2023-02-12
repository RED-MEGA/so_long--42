/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:26:08 by reben-ha          #+#    #+#             */
/*   Updated: 2023/02/12 19:05:52 by reben-ha         ###   ########.fr       */
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
	void	*mlx;
	void	*mlx_win;

	if (argc <= 1)
		return (ft_printf(2, "Error : Invalid argument\n"), 1);
	ft_input_manage(argv[1]);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);





	// system("leaks so_long");
}
