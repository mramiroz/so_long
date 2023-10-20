/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 06:48:13 by mramiro-          #+#    #+#             */
/*   Updated: 2023/10/20 11:42:49 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_game *game)
{
	int cell_size;
	int i;
	int j;
	int x;
	int y;

	cell_size = 30;
	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.columns)
		{
			x = j * cell_size;
			y = i * cell_size;
			if (game->map.map[i][j] == '1')
			{
				mlx_put_image_to_window(game->win.id, game->win.win,
					game->sprites.wall.img, x, y);
			}
			else
			{
				mlx_put_image_to_window(game->win.id, game->win.win,
					game->sprites.floor.img, x, y);
			}
			j++;
		}
		i++;
	}
}

void	init_game(t_game *game, char **argv)
{
	game->map.map = valid_map(argv[1]);
	game->map.rows = len_double(game->map.map);
	game->map.columns = ft_strlen(game->map.map[0]) - 1;

	game->win.id = mlx_init();
	game->win.width = (ft_strlen(game->map.map[0]) - 1) * 30;
	game->win.height = len_double(game->map.map) * 30;
	game->win.win = mlx_new_window(game->win.id, game->win.width,
			game->win.height, "so_long");

	//CARGA SPRITES
	game->sprites.wall.img = mlx_xpm_file_to_image(game->win.id,
			"./sprites/wall.xpm", &game->sprites.wall.width,
			&game->sprites.wall.height);
	if (!game->sprites.floor.img)
		ft_error("Error loading texture1");
	game->sprites.wall.path = "./sprites/wall.xpm";

	game->sprites.floor.img = mlx_xpm_file_to_image(game->win.id,
			"./sprites/floor.xpm", &game->sprites.floor.width,
			&game->sprites.floor.height);
	if (!game->sprites.floor.img)
		ft_error("Error loading texture2");
	game->sprites.floor.path = "./sprites/floor.xpm";
	draw_map(game);
}
