/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:27:25 by mramiro-          #+#    #+#             */
/*   Updated: 2023/10/20 11:12:45 by mramiro-         ###   ########.fr       */
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
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct s_map
{
	char	**map;
	int		rows;
	int		columns;
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
}	t_sprites;

typedef struct s_game
{
	t_win		win;
	t_map		map;
	t_sprites	sprites;
}	t_game;

char **valid_map(const char *file);
void    ft_error(char *str);
void    init_game(t_game *game, char **argv);
int     key_hook(int key, void *param);
t_img	create_img(t_win win, int w, int h);
int len_double(char **str);

#endif 