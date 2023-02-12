# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 16:20:52 by reben-ha          #+#    #+#              #
#    Updated: 2023/02/13 00:21:40 by reben-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_substr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strnstr.c \
		ft_strlen.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_split.c \
		get_next_line.c \
		get_next_line_utils.c \
		ft_printf.c \
		ft_putchar_printf.c \
		ft_putnbr_hex_printf.c \
		ft_putnbr_pos_printf.c \
		ft_putnbr_printf.c \
		ft_putptr_printf.c \
		ft_putstr_printf.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_lstadd_back.c \
		ft_lstclear.c \
		ft_lstlast.c \
		ft_itoa.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)

%.o : %.c libft.h
	gcc -g -Wall -Wextra -Werror -Imlx -c $< -o $@

clean :
	rm -f $(OBJ)
	rm -f libft.h.gch

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re

#./libft/ft_substr.c ./libft/ft_strdup.c ./libft/ft_strjoin.c ./libft/ft_strnstr.c ./libft/ft_strlen.c ./libft/ft_strrchr.c ./libft/ft_strncmp.c ./libft/ft_split.c ./libft/get_next_line.c ./libft/get_next_line_utils.c ./libft/ft_printf.c ./libft/ft_putchar_printf.c ./libft/ft_putnbr_hex_printf.c ./libft/ft_putnbr_pos_printf.c ./libft/ft_putnbr_printf.c ./libft/ft_putptr_printf.c ./libft/ft_putstr_printf.c ./libft/ft_lstnew.c ./libft/ft_lstsize.c ./libft/ft_lstadd_back.c ./libft/ft_lstclear.c ./libft/ft_lstlast.c