# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysouhail <ysouhail@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/31 22:43:46 by ysouhail          #+#    #+#              #
#    Updated: 2024/06/11 20:08:15 by ysouhail         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME := libft.a

HEADER := libft.h

CC := cc

CFLAGS := -Wall -Wextra -Werror

SRCS := ft_atoi.c	ft_strchr.c	ft_bzero.c	ft_itoa.c	ft_strmapi.c	ft_putendl_fd.c\
	ft_strdup.c	ft_calloc.c	ft_strlcat.c	ft_strtrim.c	ft_striteri.c\
	ft_strjoin.c	ft_isalnum.c		ft_isalpha.c	ft_split.c	ft_putchar_fd.c\
	ft_strlcpy.c	ft_isascii.c	ft_strlen.c	ft_isdigit.c	ft_strncmp.c	ft_putnbr_fd.c\
	ft_isprint.c	ft_strnstr.c	ft_strrchr.c	ft_memcmp.c	ft_putstr_fd.c\
	ft_substr.c	ft_memcpy.c	ft_tolower.c	ft_memmove.c	ft_toupper.c	ft_memset.c\

BONUSSRC := ft_lstnew_bonus.c	ft_lstadd_front_bonus.c	ft_lstsize_bonus.c\
	ft_lstlast_bonus.c\
	
OBJS :=	$(SRCS:.c=.o)

BONUSOBJS:= $(BONUSSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	ar rcs $(NAME) $(OBJS)
 
bonus: $(BONUSOBJS) $(HEADER)
	ar rcs $(NAME) $(BONUSOBJS)

clean:
	rm -rf $(OBJS) $(BONUSOBJS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re