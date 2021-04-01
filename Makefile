NAME = cub3D

MLX_DIR = ./mlx
SRC_DIR = ./srcs/*
INC_DIR = ./inc
OBJ_DIR = ./obj

SRC = $(wildcard $(SRC_DIR)/*.c) srcs/main.c srcs/game_loop.c
OBJ = $(SRC:.c=.o)

CC = clang
FLAGS = -O3 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	make -C ./mlx -lmlx
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) libft/libft.a -L $(MLX_DIR) -lmlx -lXext -lX11 -lm

%.o: %.c
	$(CC) -g -I$(INC_DIR) -I$(MLX_DIR) -o $@ -c $<

bonus : all

clean:
	cd libft/ ; make clean ; cd ../
	rm -rf $(OBJ)

fclean: clean
	cd mlx/ ; make clean ; cd ../
	cd libft/ ; make fclean ; cd ../
	rm -rf $(NAME)

re: fclean all
