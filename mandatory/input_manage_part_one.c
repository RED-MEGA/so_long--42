/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_manage_part_one.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 01:01:25 by reben-ha          #+#    #+#             */
/*   Updated: 2023/02/16 23:32:05 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_loc	fp(char **map, char c, int option)
{
	t_loc	loc;
	int		count;

	loc.i = -1;
	count = 0;
	while (map[++loc.i])
	{
		loc.j = -1;
		while (map[loc.i][++loc.j])
		{
			if (map[loc.i][loc.j] == c)
			{
				count++;
				if (option == 'l')
					return (loc);
			}
		}
	}
	if (option == 'n' || count > 0)
	{
		loc.i = count;
		return (loc);
	}
	loc.i = -1;
	return (loc);
}

void	check_ex_nb(char **map)
{
	int	i;
	int	j;

	if (fp(map, 'P', 'n').i != 1 || fp(map, 'E', 'n').i != 1 || (fp(map, '0', 'n').i < 1)
		|| (fp(map, '1', 'n').i < 1) || fp(map, 'C', 'n').i < 1)
		return (ft_printf(2, "Error : Invalid Character\n"), exit(1));
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!(map[i][j] == '0') && !(map[i][j] == '1') && !(map[i][j] == 'C')
					&& !(map[i][j] == 'P') && !(map[i][j] == 'E'))
				return (ft_printf(2, "Error : Invalid Character\n"), exit(1));
		}
	}
}

char	**ft_input_manage(char *map_file)
{
	int		fd;
	int		len;
	char	*str;
	char	*full_map;
	char	**map;

	if (ft_strlen(map_file) < 5 || ft_strncmp(ft_strrchr(map_file, '.'), ".ber\0", 5) != 0)
		return (ft_printf(2, "Error : Invalid argument\n"), exit(1), NULL);
	fd = open(map_file, O_RDONLY);
	ft_error(fd, 1);
	full_map = NULL;
	str = NULL;
	while (1)
	{
		free(str);
		str = get_next_line(fd);
		if (!str)
			break ;
		full_map = ft_strjoin(full_map, str);
	}
	map = ft_split(full_map, '\n');
	free(full_map);
	len = 0;
	while (map[len])
		len++;
	check_ex_nb(map);
	check_map(map, len - 1);
	return (map);
}
