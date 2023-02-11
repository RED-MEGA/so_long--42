# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 23:26:08 by reben-ha          #+#    #+#              #
#    Updated: 2023/02/11 01:08:19 by reben-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIB = ./libft/libft.a

SRC = so_long.c \
		mandatory/input_manage_part_one.c \
		mandatory/input_manage_part_two.c

OBJ = $(SRC:.c=.o)

#BSRC = 

#BOBJ = 

LIB_OBJ = ./libft/ft_substr.o \
		./libft/ft_strdup.o \
		./libft/ft_strjoin.o \
		./libft/ft_strnstr.o \
		./libft/ft_strlen.o \
		./libft/ft_strrchr.o \
		./libft/ft_strncmp.o \
		./libft/ft_split.o \
		./libft/get_next_line.o \
		./libft/get_next_line_utils.o \
		./libft/ft_printf.o \
		./libft/ft_putchar_printf.o \
		./libft/ft_putnbr_hex_printf.o \
		./libft/ft_putnbr_pos_printf.o \
		./libft/ft_putnbr_printf.o \
		./libft/ft_putptr_printf.o \
		./libft/ft_putstr_printf.o \
		./libft/ft_lstnew.o \
		./libft/ft_lstsize.o \
		./libft/ft_lstadd_back.o \
		./libft/ft_lstclear.o \
		./libft/ft_lstlast.o

all : $(NAME)

$(NAME) : $(OBJ) $(LIB) $(LIB_OBJ)
	gcc -g $(OBJ) $(LIB) -o $(NAME)
# -Wall -Wextra -Werror
$(LIB) : ./libft/libft.h
	make -C ./libft

%.o : %.c so_long.h
	gcc -g -c $< -o $@
#-Wall -Wextra -Werror
# bonus : $(BOBJ) $(LIB) $(LIB_OBJ)
#         rm -f $(OBJ)
#         cc -Wall -Wextra -Werror $(BOBJ) $(LIB) -o $(NAME)

# %_bonus.o : %_bonus.c pipex_bonus.h
#         cc -Wall -Wextra -Werror -c $< -o $@

clean :
	rm -f $(OBJ)
	make fclean -C ./libft

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re