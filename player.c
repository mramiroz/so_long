/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:12:57 by mramiro-          #+#    #+#             */
/*   Updated: 2023/10/23 09:55:41 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_game *game)
{
	game->player.x_old = game->player.x;
	game->player.y_old = game->player.y;
	if (game->map.map[game->player.y][game->player.x - 1] != '1')
	{
		game->player.x -= 1;
		game->player.moves += 1;
		draw_player(game);
	}
}

void	move_right(t_game *game)
{
	game->player.x_old = game->player.x;
	game->player.y_old = game->player.y;
	if (game->map.map[game->player.y][game->player.x + 1] != '1')
	{
		game->player.x += 1;
		game->player.moves += 1;
		draw_player(game);
	}
}

void	move_up(t_game *game)
{
	game->player.y_old = game->player.y;
	game->player.x_old = game->player.x;
	if (game->map.map[game->player.y - 1][game->player.x] != '1')
	{
		game->player.y -= 1;
		game->player.moves += 1;
		draw_player(game);
	}
}

void	move_down(t_game *game)
{
	game->player.y_old = game->player.y;
	game->player.x_old = game->player.x;
	if (game->map.map[game->player.y + 1][game->player.x] != '1')
	{
		game->player.y += 1;
		game->player.moves += 1;
		draw_player(game);
	}
}