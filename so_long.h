/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:27:25 by mramiro-          #+#    #+#             */
/*   Updated: 2023/10/23 09:40:45 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"
# include "libft/libft.h"

// CONSTANTES KEYS
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_Q 113
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

typedef struct s_map
{
	char	**map;
	int		rows;
	int		columns;
	int		collectibles;
}	t_map;

typedef struct s_win
{
	void	*id;
	void	*win;
	int		width;
	int		height;
}	t_win;


typedef struct s_img
{
	t_win	win;
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_length;
	int		endian;
	char	*path;
}	t_img;

typedef struct s_sprites
{
	t_img	wall;
	t_img	floor;
	t_img	collectible;
	t_img	exit;
}	t_sprites;

typedef struct s_player
{
	t_img	img;
	int	x;
	int	y;
	int	x_old;
	int y_old;
	int moves;
	int collectibles;
} t_player;

typedef struct s_game
{
	t_win		win;
	t_map		map;
	t_sprites	sprites;
	t_player	player;
}	t_game;


void	valid_map(t_game *game, const char *file);
void	ft_error(char *str);
void	init_game(t_game *game, char **argv);
int		key_hook(int key, void *param);
t_img	create_img(t_win win, int w, int h);
int		len_double(char **str);
int		exit_game(void *game);
void	load_sprites(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	draw_map(t_game *game);
void	draw_player(t_game *game);

#endif
