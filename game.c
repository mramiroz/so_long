/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 06:48:13 by mramiro-          #+#    #+#             */
/*   Updated: 2024/04/16 10:21:54 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	counter(t_game *game)
{
	char	*num;

	game->player.moves++;
	mlx_put_image_to_window(game->win.id, game->win.win,
		game->sprites.wall.img, 0,
		0);
	mlx_put_image_to_window(game->win.id, game->win.win,
		game->sprites.wall.img, 1 * TILE_SIZE, 0);
	num = ft_itoa(game->player.moves);
	mlx_string_put(game->win.id, game->win.win, 5, 5, 0x00FFFFFF,
		num);
	free(num);
}

void	check_sprite(t_game *game, int i, int j)
{
	if (game->map.map[i][j] == '1')
		mlx_put_image_to_window(game->win.id, game->win.win,
			game->sprites.wall.img, (j * TILE_SIZE), (i * TILE_SIZE));
	else
	{
		mlx_put_image_to_window(game->win.id, game->win.win,
			game->sprites.floor.img, (j * TILE_SIZE), (i * TILE_SIZE));
		if (game->map.map[i][j] == 'C')
		{
			mlx_put_image_to_window(game->win.id, game->win.win,
				game->sprites.collectible.img, (j * TILE_SIZE),
				(i * TILE_SIZE));
		}
		else if (game->map.map[i][j] == 'P')
		{
			game->player.x = j;
			game->player.y = i;
			mlx_put_image_to_window(game->win.id, game->win.win,
				game->player.img.img, (j * TILE_SIZE), (i * TILE_SIZE));
		}
		else if (game->map.map[i][j] == 'E')
			mlx_put_image_to_window(game->win.id, game->win.win,
				game->sprites.exit.img, (j * TILE_SIZE), (i * TILE_SIZE));
	}
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->player.collectibles = 0;
	game->player.moves = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j <= game->map.columns)
			(check_sprite(game, i, j), j++);
		i++;
	}
	game->player.x_old = game->player.x;
	game->player.y_old = game->player.y;
}

void	draw_player(t_game *game)
{
	if (game->map.map[game->player.y][game->player.x] == 'E' &&
		game->player.collectibles == game->map.collectibles)
		exit_game(game);
	mlx_put_image_to_window(game->win.id, game->win.win,
		game->sprites.floor.img, (game->player.x_old * TILE_SIZE),
		(game->player.y_old * TILE_SIZE));
	if (game->map.map[game->player.y][game->player.x] == 'C')
	{
		game->map.map[game->player.y][game->player.x] = '0';
		game->player.collectibles++;
	}
	mlx_put_image_to_window(game->win.id, game->win.win,
		game->player.img.img, (game->player.x * TILE_SIZE),
		(game->player.y * TILE_SIZE));
}

void	init_game(t_game *game, t_aux *aux, char **argv)
{
	valid_map(game, argv[1]);
	copy_game(game, aux);
	if (!valid_path(aux))
		ft_error_map("Error path not found", game->map.map);
	game->win.id = mlx_init();
	game->win.width = (ft_strlen(game->map.map[0])) * TILE_SIZE;
	game->win.height = len_double(game->map.map) * TILE_SIZE;
	game->win.win = mlx_new_window(game->win.id, game->win.width,
			game->win.height, "so_long");
	load_sprites(game);
	draw_map(game);
}
