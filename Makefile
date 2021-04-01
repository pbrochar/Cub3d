NAME = cub3D

LIB = -Lmlx -lmlx -L/usr/lib -lXext -lX11 -lm
SRC_DIR = ./srcs/*
INC_DIR = ./inc
OBJ_DIR = ./obj

SRC = $(wildcard $(SRC_DIR)/*.c) srcs/main.c srcs/game_loop.c
OBJ = $(SRC:.c=.o)

CC = clang
FLAGS = -O3 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(MLX) $(OBJ)
	cd libft/ ; make ; cd ../
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIB) libft/libft.a

%.o: %.c
	$(CC) -g -I$(INC_DIR) -o $@ -c $<

$(MLX):
	cd mlx
	make

bonus : all

clean:
	cd libft/ ; make clean ; cd ../
	rm -rf $(OBJ)

fclean: clean
	cd mlx/ ; make clean ; cd ../
	cd libft/ ; make fclean ; cd ../
	rm -rf $(NAME)

re: fclean all