/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:12:57 by mramiro-          #+#    #+#             */
/*   Updated: 2023/10/25 13:18:37 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_game *game)
{
	if (game->map.map[game->player.y - 1][game->player.x] != '1' &&
		game->map.map[game->player.y - 1][game->player.x] != 'E')
		game->player.y -= 1;
	else if (game->map.map[game->player.y - 1][game->player.x] == 'E' &&
		game->player.collectibles == game->map.collectibles)
			game->player.y -= 1;
	else
		return (0);
	return (1);
}

int	move_down(t_game *game)
{
	if (game->map.map[game->player.y + 1][game->player.x] != '1' &&
		game->map.map[game->player.y + 1][game->player.x] != 'E')
		game->player.y += 1;
	else if (game->map.map[game->player.y + 1][game->player.x] == 'E' &&
		game->player.collectibles == game->map.collectibles)
			game->player.y += 1;
	else
		return (0);
	return (1);
}

int	move_left(t_game *game)
{
	if (game->map.map[game->player.y][game->player.x - 1] != '1' &&
		game->map.map[game->player.y][game->player.x - 1] != 'E')
			game->player.x -= 1;
	else if (game->map.map[game->player.y][game->player.x - 1] == 'E' &&
		game->player.collectibles == game->map.collectibles)
				game->player.x -= 1;
	else
		return (0);
	return (1);
}

int	move_right(t_game *game)
{
	if (game->map.map[game->player.y][game->player.x + 1] != '1' &&
		game->map.map[game->player.y][game->player.x + 1] != 'E')
			game->player.x += 1;
	else if (game->map.map[game->player.y][game->player.x + 1] == 'E' &&
		game->player.collectibles == game->map.collectibles)
				game->player.x += 1;
	else
		return (0);
	return (1);
}

void	moves(t_game *game, int key)
{
	int	res;

	res = 0;
	game->player.x_old = game->player.x;
	game->player.y_old = game->player.y;
	if (key == KEY_W || key == KEY_UP)
		res = move_up(game);
	else if (key == KEY_A || key == KEY_LEFT)
		res = move_left(game);
	else if (key == KEY_S || key == KEY_DOWN)
		res = move_down(game);
	else if (key == KEY_D || key == KEY_RIGHT)
		res = move_right(game);
	if (res == 1)
	{
		draw_player(game);
		counter(game);
	}
}
