/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_manage_part_two.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 01:01:27 by reben-ha          #+#    #+#             */
/*   Updated: 2023/02/21 20:23:48 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**copy_map(char **map, int len)
{
	char	**new_map;
	int		i;

	new_map = (char **)malloc(len * sizeof(char *) + 1);
	i = -1;
	while (map[++i])
		new_map[i] = ft_strdup(map[i]);
	new_map[i] = NULL;
	return (new_map);
}

void	path_player(char **map, int i, int j)
{
	if (map[i - 1][j] == '0' || map[i - 1][j] == 'C')
	{
		map[i - 1][j] = 'P';
		path_player(map, i - 1, j);
	}
	if (map[i + 1][j] == '0' || map[i + 1][j] == 'C')
	{
		map[i + 1][j] = 'P';
		path_player(map, i + 1, j);
	}
	if (map[i][j + 1] == '0' || map[i][j + 1] == 'C')
	{
		map[i][j + 1] = 'P';
		path_player(map, i, j + 1);
	}
	if (map[i][j - 1] == '0' || map[i][j - 1] == 'C')
	{
		map[i][j - 1] = 'P';
		path_player(map, i, j - 1);
	}
}

void	check_player(char **map, int i, int j)
{
	t_loc	loc;

	path_player(map, i, j);
	loc = fp(map, 'E', 'l');
	if (!(map[loc.i + 1][loc.j] == 'P')
			&& !(map[loc.i - 1][loc.j] == 'P')
			&& !(map[loc.i][loc.j + 1] == 'P')
			&& !(map[loc.i][loc.j - 1] == 'P'))
		return (ft_printf(2,
				"Error : The player is not able to go into exit"),
			exit(1));
	if (fp(map, 'C', 'l').i != -1)
		return (ft_printf(2,
				"Error : The player is not able take all Collectable"),
			exit(1));
	ft_free(map);
}

void	check_map(char **map, int len)
{
	size_t	top_line;
	int		i;
	t_loc	loc;

	top_line = ft_strlen(map[0]);
	i = -1;
	while (map[++i])
		if (top_line != ft_strlen(map[i]))
			return (ft_printf(2, "Error : Map not rectangle\n"), exit(1));
	top_line -= 1;
	i = -1;
	while (++i <= (int)top_line)
		if (map[0][i] != '1' || map[len][i] != '1')
			return (ft_printf(2, "Error : Edges not fill with 1\n"), exit(1));
	i = -1;
	while (++i <= len)
		if (map[i][0] != '1' || map[i][top_line] != '1')
			return (ft_printf(2, "Error : Edges not fill with 1\n"), exit(1));
	loc = fp(map, 'P', 'l');
	check_player(copy_map(map, len + 1), loc.i, loc.j);
}
