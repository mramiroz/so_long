/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:57:25 by mramiro-          #+#    #+#             */
/*   Updated: 2023/10/23 09:56:21 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	to_xpm(t_game *game)
{
	game->sprites.wall.img = mlx_xpm_file_to_image(game->win.id,
			game->sprites.wall.path, &game->sprites.wall.width,
			&game->sprites.wall.height);
	if (!game->sprites.wall.img)
		ft_error("Error\nWall sprite not found\n");
	game->sprites.floor.img = mlx_xpm_file_to_image(game->win.id,
			game->sprites.floor.path, &game->sprites.floor.width,
			&game->sprites.floor.height);
	if (!game->sprites.floor.img)
		ft_error("Error\nFloor sprite not found\n");
	game->sprites.collectible.img = mlx_xpm_file_to_image(game->win.id,
			game->sprites.collectible.path, &game->sprites.collectible.width,
			&game->sprites.collectible.height);
	if (!game->sprites.collectible.img)
		ft_error("Error\nCollectible sprite not found\n");
	game->player.img.img = mlx_xpm_file_to_image(game->win.id,
			game->player.img.path, &game->player.img.width,
			&game->player.img.height);
	if (!game->player.img.img)
		ft_error("Error\nPlayer sprite not found\n");
	game->sprites.exit.img = mlx_xpm_file_to_image(game->win.id,
			game->sprites.exit.path, &game->sprites.exit.width,
			&game->sprites.exit.height);
}

void	load_sprites(t_game *game)
{
	game->sprites.wall.path = "sprites/wall.xpm";
	game->sprites.floor.path = "sprites/floor.xpm";
	game->player.img.path = "sprites/mario.xpm";
	game->sprites.collectible.path = "sprites/colec.xpm";
	game->sprites.exit.path = "sprites/exit.xpm";

	to_xpm(game);
}