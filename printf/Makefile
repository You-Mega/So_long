# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysouhail <ysouhail@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 13:19:01 by ysouhail          #+#    #+#              #
#    Updated: 2024/01/24 23:29:03 by ysouhail         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

CC := cc

CFLAGS := -Wall -Wextra -Werror

SRC := ft_printf.c	ft_putchar.c	ft_putnbr.c	ft_putstr.c	ft_puthexa.c	ft_putptr.c	ft_putunsigned.c	\

HEADER := ft_printf.h

OBJ := $(SRC:.c=.o)

all : $(NAME) 

$(NAME) : $(OBJ) $(HEADER)
	ar rcs $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : clean fclean all

.PHONY : all clean fclean re 