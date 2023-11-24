/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 06:48:13 by mramiro-          #+#    #+#             */
/*   Updated: 2023/11/24 08:19:38 by mramiro-         ###   ########.fr       */
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
	num = ft_itoa(game->player.moves);
	mlx_string_put(game->win.id, game->win.win, 6, 6, 0x00FFFFFF,
		num);
	free(num);
}

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
		{
			mlx_put_image_to_window(game->win.id, game->win.win,
				game->sprites.collectible.img, (j * cell_size),
				(i * cell_size));
		}
		else if (game->map.map[i][j] == 'P')
		{
			game->player.x = j;
			game->player.y = i;
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
	game->player.collectibles = 0;
	game->player.moves = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.columns)
			(check_sprite(game, i, j, cell_size), j++);
		i++;
	}
	game->player.x_old = game->player.x;
	game->player.y_old = game->player.y;
}

void	draw_player(t_game *game)
{
	int	cell_size;

	cell_size = 30;
	if (game->map.map[game->player.y][game->player.x] == 'E' &&
		game->player.collectibles == game->map.collectibles)
		exit_game(game);
	mlx_put_image_to_window(game->win.id, game->win.win,
		game->sprites.floor.img, (game->player.x_old * cell_size),
		(game->player.y_old * cell_size));
	if (game->map.map[game->player.y][game->player.x] == 'C')
	{
		game->map.map[game->player.y][game->player.x] = '0';
		game->player.collectibles++;
	}
	mlx_put_image_to_window(game->win.id, game->win.win,
		game->player.img.img, (game->player.x * cell_size),
		(game->player.y * cell_size));
}

void	init_game(t_game *game, t_aux *aux, char **argv)
{
	valid_map(game, argv[1]);
	game->win.id = mlx_init();
	game->win.width = (ft_strlen(game->map.map[0]) - 1) * 30;
	game->win.height = len_double(game->map.map) * 30;
	game->win.win = mlx_new_window(game->win.id, game->win.width,
			game->win.height, "so_long");
	copy_game(game, aux);
	if (!valid_path(aux))
		ft_error_map("Error path not found", game->map.map);
	load_sprites(game);
	draw_map(game);
}
