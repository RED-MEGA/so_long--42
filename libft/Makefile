# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 16:20:52 by reben-ha          #+#    #+#              #
#    Updated: 2023/02/09 00:21:52 by reben-ha         ###   ########.fr        #
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
		ft_lstlast.c

OBJ = ft_substr.o \
		ft_strdup.o \
		ft_strjoin.o \
		ft_strnstr.o \
		ft_strlen.o \
		ft_strrchr.o \
		ft_strncmp.o \
		ft_split.o \
		get_next_line.o \
		get_next_line_utils.o \
		ft_printf.o \
		ft_putchar_printf.o \
		ft_putnbr_hex_printf.o \
		ft_putnbr_pos_printf.o \
		ft_putnbr_printf.o \
		ft_putptr_printf.o \
		ft_putstr_printf.o \
		ft_lstnew.o \
		ft_lstsize.o \
		ft_lstadd_back.o \
		ft_lstclear.o \
		ft_lstlast.o

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)

%.o : %.c libft.h
	cc -Wall -Wextra -Werror -c $< -o $@

clean :
	rm -f $(OBJ)
	rm -f libft.h.gch

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re