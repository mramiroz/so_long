/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:57:25 by mramiro-          #+#    #+#             */
/*   Updated: 2023/10/23 10:00:15 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void xpm_image(t_img *img, t_game *game)
{
	img->img = mlx_xpm_file_to_image(game->win.id,
			img->path, &img->width,
			&img->height);
	if (!img->img)
		ft_error("Error\nImage not found\n");
}

void	to_xpm(t_game *game)
{
	xpm_image(&game->sprites.wall, game);
	xpm_image(&game->sprites.floor, game);
	xpm_image(&game->player.img, game);
	xpm_image(&game->sprites.collectible, game);
	xpm_image(&game->sprites.exit, game);
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