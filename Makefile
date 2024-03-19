NAME = so_long
SRC = main.c check_map.c utils.c game.c keys.c sprites.c player.c check_map2.c error.c check_path.c
LIBFT = libft/ft_strlen.c libft/ft_strncmp.c libft/ft_split.c libft/ft_calloc.c libft/ft_strdup.c libft/ft_strjoin.c libft/ft_bzero.c libft/ft_strlcpy.c \
		libft/ft_itoa.c libft/ft_memset.c
OBJ = $(SRC:.c=.o)
OBJ += $(LIBFT:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -lmlx -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re