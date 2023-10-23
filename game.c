/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 06:48:13 by mramiro-          #+#    #+#             */
/*   Updated: 2023/10/23 09:54:56 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_sprite(t_game *game, int i, int j, int cell_size)
{
	if (game->map.map[i][j] == '1')
		mlx_put_image_to_window(game->win.id, game->win.win,
			game->sprites.wall.img, (j * cell_size), (i * cell_size));
	else
	{
		mlx_put_image_to_window(game->win.id, game->win.win,
			game->sprites.floor.img, (j * cell_size), (i * cell_size));
		if (game->map.map[i][j] == 'C')
			mlx_put_image_to_window(game->win.id, game->win.win,
				game->sprites.collectible.img, (j * cell_size),
				(i * cell_size));
		else if (game->map.map[i][j] == 'P')
		{
			game->player.x = j;
			game->player.y = i;
			game->player.x_old = j;
			game->player.y_old = i;
			game->player.moves = 0;
			mlx_put_image_to_window(game->win.id, game->win.win,
				game->player.img.img, (j * cell_size), (i * cell_size));
		}
		else if (game->map.map[i][j] == 'E')
			mlx_put_image_to_window(game->win.id, game->win.win,
				game->sprites.exit.img, (j * cell_size), (i * cell_size));
	}
}

void	draw_map(t_game *game)
{
	int	cell_size;
	int	i;
	int	j;

	cell_size = 30;
	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.columns)
			(check_sprite(game, i, j, cell_size), j++);
		i++;
	}
}

void	draw_player(t_game *game)
{
	int	cell_size;

	cell_size = 30;
	if (game->map.map[game->player.y][game->player.x] == 'E')
		exit_game(game);
	mlx_put_image_to_window(game->win.id, game->win.win,
		game->sprites.floor.img, (game->player.x_old * cell_size),
		(game->player.y_old * cell_size));
	mlx_put_image_to_window(game->win.id, game->win.win,
		game->player.img.img, (game->player.x * cell_size),
		(game->player.y * cell_size));
}

void	init_game(t_game *game, char **argv)
{
	valid_map(game, argv[1]);
	game->map.rows = len_double(game->map.map);
	game->map.columns = ft_strlen(game->map.map[0]) - 1;
	game->win.id = mlx_init();
	game->win.width = (ft_strlen(game->map.map[0]) - 1) * 30;
	game->win.height = len_double(game->map.map) * 30;
	game->win.win = mlx_new_window(game->win.id, game->win.width,
			game->win.height, "so_long");
	load_sprites(game);
	draw_map(game);
}
