/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:26:08 by reben-ha          #+#    #+#             */
/*   Updated: 2023/02/10 00:50:11 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_error(int status, int code)
{
	if (status == FAIL)
		return (perror("Error "), exit(code));
}

t_loc	fp(char **map)
{
	t_loc	loc;

	loc.i = -1;
	while (map[loc.i])
	{
		loc.j = -1;
		while (map[loc.i][++loc.j])
		{
			if (map[loc.i][loc.j] == 'P')
				return (loc);
		}
	}
	return (loc);
}

char	**copy_map(char **map, int len)
{
	char	**new_map;
	int		i;

	new_map = (char **)malloc(len * sizeof(char *));
	i = -1;
	while (map[++i])
		new_map[i] = ft_strdup(map[i]);
	return (new_map);
}

void	check_player(char **map, int i, int j)
{
	if (map[i - 1][j] == '0' || map[i - 1][j] == 'C')
	{
		map[i - 1][j] = 'P';
		check_player(map, i - 1, j);
	}
	if (map[i + 1][j] == '0' || map[i + 1][j] == 'C')
	{
		map[i + 1][j] = 'P';
		check_player(map, i + 1, j);
	}
	if (map[i][j + 1] == '0' || map[i][j + 1] == 'C')
	{
		map[i][j + 1] = 'P';
		check_player(map, i, j + 1);
	}
	if (map[i][j - 1] == '0' || map[i][j - 1] == 'C')
	{
		map[i][j - 1] = 'P';
		check_player(map, i, j - 1);
	}
}

void	check_map(char **map, int len)
{
	// size_t	top_line;
	// int		i;

	// top_line = ft_strlen(map[0]);
	// i = 0;
	// while (map[++i])
	// {
	// 	printf("%d = %s ?", i, map[i]);
	// 	if (top_line != ft_strlen(map[i]))
	// 		return (ft_printf(2, "Error : Map not rectangle\n"));
	// }
	// i = 0;
	// while (map[0][i] && map[len][i])
	// {
	// 	if (map[0][i] != 1 || map[len][i] != 1)
	// 		return (ft_printf(2, "Error : Edges not fill with 1\n"));
	// }
	// len = top_line - 1;
	// i = 0;
	// while (map[i][0] && map[i][len])
	// {
	// 	if (map[0][i] != 1 || map[len][i] != 1)
	// 		return (ft_printf(2, "Error : Edges not fill with 1\n"));
	// }
	char **str = copy_map(map, len);
	check_player(str, fp(map).i, fp(map).j);
	for (size_t i = 0; i < 12; i++)
	{
		printf("%s", map[i]);
	}
}

void	ft_input_manage(char *map_file)
{
	int		fd;
	int		i;
	int		len;
	char	*str;
	char	**map;

	if (ft_strncmp(ft_strrchr(map_file, '.'), ".ber", 4) != 0)
		return (ft_printf(2, "Error : Invalid argument\n"), exit(1));
	fd = open(map_file, O_RDONLY);
	ft_error(fd, 1);
	i = 0;
	while (1)
	{
		str = get_next_line(fd);
		free(str);
		if (!str)
			break ;
		i++;
	}
	len = i;
	if (str == NULL && i == 0)
		return (ft_printf(2, "Error : File is empty\n"), exit(1));
	map = (char **)malloc(len * sizeof(char *));
	close(fd);
	fd = open(map_file, O_RDONLY);
	ft_error(fd, 1);
	i = -1;
	while (1)
	{
		map[++i] = get_next_line(fd);
		if (!map[i])
			break ;
	}
	check_map(map, i);
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
		return (ft_printf(2, "Error : Invalid argument\n"), 1);
	ft_input_manage(argv[1]);
}
