CC = cc

NAME = so_long

CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast

LIBMLX	:= /Users/ysouhail/MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include

LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

RM = rm -rf

LIBFT = ./libft/libft.a

PRINTF	= ./printf/libftprintf.a

SOURCE = so_long.c	utils.c utils2.c moves.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ = $(SOURCE:.c=.o)

$(NAME) : $(OBJ)
	@make -C ./libft
	@make -C ./printf
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF) $(LIBFT) $(LIBS) $(HEADERS) -o $(NAME)

all : libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS) && printf "Compiling: $(notdir $<)"

clean:
	make clean -C libft
	make clean -C printf
	rm -rf $(LIBMLX)/build
	$(RM) $(OBJ)

fclean : clean
	make fclean -C printf
	make fclean -C libft
	$(RM) $(NAME)

re : fclean all

.PHONY: clean fclean all re