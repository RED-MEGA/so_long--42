/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:26:10 by reben-ha          #+#    #+#             */
/*   Updated: 2023/02/24 14:01:16 by reben-ha         ###   ########.fr       */
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

# define MAX_TIME 5000000
# define FAIL -1
# define KEYPRESS 2
# define DESTROYNOTIFY 17

# define UP_KEY		126
# define DOWN_KEY	125
# define LEFT_KEY	123
# define RIGHT_KEY	124
# define W_KEY		13
# define S_KEY		1
# define A_KEY		0
# define D_KEY		2

typedef struct s_struct
{
	int		i;
	int		j;
}			t_loc;

typedef struct s_frame
{
	void	*frame_1;
	void	*frame_2;
	void	*frame_3;
	void	*frame_4;
	void	*frame_5;
	void	*frame_6;
	void	*frame_7;
	void	*frame_8;
	void	*frame_9;
	void	*frame_10;
}			t_frame;

typedef struct s_player
{
	void	*main;
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
	void		*exit_2;
	t_frame		exit_hole;
	void		*enemy;
	void		*enemy_angry;
	void		*blade;
	void		*start;
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
	int		time_midgard;
	int		time_enemy;
	int		frame;
}			t_mlx_win;

void	ft_error(int status, int code);
void	ft_error_str(void *status, int code);
void	ft_free(char **str);
void	ft_destroy(t_mlx_win *mlx_x);

char	**ft_input_manage(char *map_file);
void	check_ex_nb(char **map);
void	check_map(char **map, int len);
char	**copy_map(char **map, int len);
void	check_player(char **map, int i, int j);
void	path_player(char **map, int i, int j);

void	ft_open_image(t_mlx_win *mlx_x);
void	ft_put_to_screen(t_mlx_win *mlx_x);
int		apply_key(int keycode, t_mlx_win *mlx_x);
void	ft_select_img(t_mlx_win *mlx_x, char *option);
int		exit_window(t_mlx_win *mlx_x);

t_loc	fp(char **map, char c, int option);

int		animation_sprite(t_mlx_win *mlx_x);
void	midgard_hole(t_mlx_win *mlx_x);
void	enemy_animated(t_mlx_win *mlx_x);

#endif