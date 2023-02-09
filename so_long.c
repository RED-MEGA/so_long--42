/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:26:08 by reben-ha          #+#    #+#             */
/*   Updated: 2023/02/09 19:21:35 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_error(int status, int code)
{
	if (status == FAIL)
		return (perror("Error "), exit(code));
}

void	ft_input_manage(char *map_file)
{
	int		fd;
	int		i;
	char	*str;
	char	**map;

	fd = open(map_file, O_RDONLY);
	ft_error(fd, 1);
	i = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		i++;
	}
	if (str == NULL && i == 0)
		return (ft_printf(2, "Error : File is empty\n"), 1);
	map = (char **)malloc(i * sizeof(char *));
	i = -1;
	while (1)
	{
		map[++i] = get_next_line(fd);
		if (!map[i])
			break ;
	}
	i = -1;
	while (map[++i])
		printf("%s\n", map[i]);
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
		return (ft_printf(2, "Error : Invalid argument"), 1);
	ft_input_manage(argv[1]);
}
