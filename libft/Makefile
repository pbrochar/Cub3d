NAME = libft.a

PF_DIR = ./ft_printf
GNL_DIR = ./get_next_line
SRCS_DIR = ./srcs

INCLUDE_DIR = ./includes

#SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	   ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c \
	   ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
	   ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c \
	   ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
	   ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
	   ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
	   ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \#

SRCS = $(wildcard $(SRCS_DIR)/*.c)
SRCS_PF = $(wildcard $(SRCS_DIR)/$(PF_DIR)/*.c)
SRCS_GNL = $(wildcard $(SRCS_DIR)/$(GNL_DIR)/*c)

OBJ = ${SRCS:.c=.o}
OBJ_PF = ${SRCS_PF:.c=.o}
OBJ_GNL = ${SRCS_GNL:.c=.o}

FLAGS = -Wall -Wextra -Werror

CC = clang

%.o : %.c
	$(CC) $(FLAGS) -c -I$(INCLUDE_DIR) $< -o ${<:.c=.o}

$(NAME) : $(OBJ) $(OBJ_PF) $(OBJ_GNL)
	ar -crs $@ $^

all : $(NAME)

clean :
	rm -f $(OBJ) 
	rm -rf $(OBJ_PF)
	rm -rf $(OBJ_GNL)
	rm -f libft.h.gch

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re 
