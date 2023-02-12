/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:26:10 by reben-ha          #+#    #+#             */
/*   Updated: 2023/02/12 19:16:21 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <mlx.h>
# include "./libft/libft.h"

#define FAIL -1

typedef struct s_struct
{
	int		i;
	int		j;
}			t_loc;

typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

void    ft_error(int status, int code);
void	ft_free(char **str);

void	ft_input_manage(char *map_file);
void	check_ex_nb(char **map);
t_loc	fp(char **map, char c, int option);
void	check_map(char **map, int len);
char	**copy_map(char **map, int len);
void	check_player(char **map, int i, int j);
void	path_player(char **map, int i, int j);

#endif