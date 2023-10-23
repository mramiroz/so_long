/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 07:55:22 by mramiro-          #+#    #+#             */
/*   Updated: 2023/10/23 08:40:35 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_destroy_window(game->win.id, game->win.win);
	exit(0);
}

int	key_hook(int key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key == KEY_ESC || key == KEY_Q)
		exit_game(game);
	else if (key == KEY_W || key == KEY_UP)
		move_up(game);
	else if (key == KEY_A || key == KEY_LEFT)
		move_left(game);
	else if (key == KEY_S || key == KEY_DOWN)
		move_down(game);
	else if (key == KEY_D || key == KEY_RIGHT)
		move_right(game);
	return (0);
}
