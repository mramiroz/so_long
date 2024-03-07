/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:00:32 by mramiro-          #+#    #+#             */
/*   Updated: 2024/03/07 09:23:49 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_exit(t_game *game, int i, int j)
{
	game->exit.x = j;
	game->exit.y = i;
	return (1);
}

int	set_player(t_game *game, int i, int j)
{
	game->player.x = j;
	game->player.y = i;
	return (1);
}

void	copy_game(t_game *game, t_aux *aux)
{
	int	i;

	i = 0;
	aux->map = malloc(sizeof(char *) * game->map.rows);
	if (aux->map == NULL)
		ft_error("Allocate error");
	while (i < game->map.rows)
	{
		aux->map[i] = ft_strdup(game->map.map[i]);
		if (aux->map[i] == NULL)
			ft_error("Allocate error");
		i++;
	}
	aux->start_x = game->player.x;
	aux->start_y = game->player.y;
	aux->end_x = game->exit.x;
	aux->end_y = game->exit.y;
	aux->collectibles = game->map.collectibles;
	aux->get_colec = 0;
	aux->rows = game->map.rows;
	aux->colums = game->map.columns;
	aux->get_exit = 0;
}
