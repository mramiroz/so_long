/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:00:32 by mramiro-          #+#    #+#             */
/*   Updated: 2023/11/24 08:19:08 by mramiro-         ###   ########.fr       */
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
}

int	valid_path_helper(t_aux *aux, int x, int y)
{
	while (!(x == aux->end_x && y == aux->end_y))
	{
		if (aux->map[y][x] == '1')
			return (0);
		else if (aux->map[y][x] == 'C')
		{
			aux->get_colec++;
			aux->map[y][x] = '0';
		}
		aux->map[y][x] = '1';
		if (valid_path_helper(aux, x, y - 1))
			return (1);
		if (valid_path_helper(aux, x, y + 1))
			return (1);
		if (valid_path_helper(aux, x - 1, y))
			return (1);
		if (valid_path_helper(aux, x + 1, y))
			return (1);
	}
	aux->map[y][x] = '1';
	if (aux->get_colec == aux->collectibles
		&& (x == aux->end_x && y == aux->end_y))
		return (1);
	return (0);
}

int	valid_path(t_aux *game)
{
	int	x;
	int	y;

	x = game->start_x;
	y = game->start_y;
	if (game->map[game->start_y][game->start_x] == '1')
		return (0);
	return (valid_path_helper(game, x, y));
}
