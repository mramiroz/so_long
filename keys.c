/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 07:55:22 by mramiro-          #+#    #+#             */
/*   Updated: 2023/10/25 09:15:08 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_destroy_window(game->win.id, game->win.win);
	free_map_char(game->map.map);
	exit(0);
}

int	key_hook(int key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key == KEY_ESC || key == KEY_Q)
		exit_game(game);
	else if (key == KEY_W || key == KEY_UP)
		moves(game, key);
	else if (key == KEY_A || key == KEY_LEFT)
		moves(game, key);
	else if (key == KEY_S || key == KEY_DOWN)
		moves(game, key);
	else if (key == KEY_D || key == KEY_RIGHT)
		moves(game, key);
	return (0);
}
