/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 09:08:09 by mramiro-          #+#    #+#             */
/*   Updated: 2023/10/23 09:50:58 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		perror("Error");
		exit(1);
	}
	init_game(&game, argv);
	printf("X: %i\n", game.player.x);
	printf("Y: %i\n", game.player.y);
	mlx_key_hook(game.win.win, key_hook, &game);
	mlx_hook(game.win.win, 17, 0, exit_game, &game);
	mlx_loop(game.win.id);
}
