/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_manage_part_one.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 01:01:25 by reben-ha          #+#    #+#             */
/*   Updated: 2023/02/12 19:59:22 by reben-ha         ###   ########.fr       */
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
	map = (char **)malloc(len * sizeof(char *) + 1);
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
	i = -1;
	while (map[++i])
	{
		str = map[i];
		map[i] = ft_substr(map[i], 0, ft_strlen(map[i]) - 1);
		free(str);
	}

	for (size_t i = 0; map[i]; i++)
		printf("%s\n", map[i]);
	
	check_ex_nb(map);
	check_map(map, i - 1);
}
