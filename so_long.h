/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:26:10 by reben-ha          #+#    #+#             */
/*   Updated: 2023/02/14 14:52:04 by reben-ha         ###   ########.fr       */
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

# define FAIL -1
# define KEYPRESS 2
# define DESTROYNOTIFY 17

// 	Hook         KeyCode
//
// 	keyup    	   126
// 	keyleft  	   123
// 	keydown  	   125
// 	keyright 	   124
// 		W	 	    13
// 		A	 		0
// 		D	 		2
// 		S	 		1

typedef struct s_struct
{
	int		i;
	int		j;
}			t_loc;

typedef struct s_player
{
	void	*front;
	void	*back;
	void	*right;
	void	*left;
}			t_player;

typedef struct s_image
{
	void		*floor;
	void		*wall;
	void		*coin;
	void		*exit;
	void		*enemy;
	t_player	player;
}			t_image;

typedef struct s_mlx_win
{
	t_image	img;
	int		x;
	int		y;
	void	*mlx;
	void	*mlx_win;
	char	**map;
	int		width;
	int		height;
	int		moves;
}			t_mlx_win;

void	ft_error(int status, int code);
void	ft_error_str(void *status, int code);
void	ft_free(char **str);
char	**ft_input_manage(char *map_file);
void	check_ex_nb(char **map);
t_loc	fp(char **map, char c, int option);
void	check_map(char **map, int len);
char	**copy_map(char **map, int len);
void	check_player(char **map, int i, int j);
void	path_player(char **map, int i, int j);

#endif