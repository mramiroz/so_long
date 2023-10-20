NAME = so_long
SRC = main.c check_map.c utils.c game.c keys.c
LIBFT = libft/ft_strlen.c libft/ft_strncmp.c libft/ft_split.c libft/ft_calloc.c libft/ft_strdup.c libft/ft_strjoin.c libft/ft_bzero.c libft/ft_strlcpy.c
GNL = gnl/get_next_line.c gnl/get_next_line_utils.c
OBJ = $(SRC:.c=.o)
OBJ += $(LIBFT:.c=.o)
OBJ += $(GNL:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L./minilibx-linux -lmlx -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -I./minilibx-linux -O3 -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re