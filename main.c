/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 09:08:09 by mramiro-          #+#    #+#             */
/*   Updated: 2023/10/25 09:23:49 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	t_aux	aux;

	if (argc != 2)
	{
		perror("Error");
		exit(1);
	}
	init_game(&game, &aux, argv);
	mlx_key_hook(game.win.win, key_hook, &game);
	mlx_hook(game.win.win, 17, 0, exit_game, &game);
	mlx_loop(game.win.id);
	free_map_char(game.map.map);
	free_map_char(aux.map);
}
