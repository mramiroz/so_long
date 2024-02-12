/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:00:32 by mramiro-          #+#    #+#             */
/*   Updated: 2024/02/08 11:19:26 by mramiro-         ###   ########.fr       */
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
	if (aux->map[y][x] == '1')
		return (0);
	if (aux->map[y][x] == 'E')
		return (1);
	aux->map[y][x] = '1';
    return (valid_path_helper(aux, x + 1, y) ||
			valid_path_helper(aux, x - 1, y) ||	
			valid_path_helper(aux, x, y + 1) ||
			valid_path_helper(aux, x, y - 1));
}

int	valid_coins(t_aux *aux, int x, int y, int **visited)
{
	if (aux->map[y][x] == '1')
		return (0);
	if (aux->collectibles == aux->get_colec)
		return (1);
	if (aux->map[y][x] == 'C')
	{
		aux->get_colec++;
		aux->map[y][x] = '0';
	}
	aux->map[y][x] = '1';

	if (valid_coins(aux, x + 1, y, visited) ||
		valid_coins(aux, x - 1, y, visited) ||
		valid_coins(aux, x, y + 1, visited) ||
		valid_coins(aux, x, y - 1, visited))
		return (1);
	aux->map[y][x] = '0';
	return (0);
}


int	valid_path(t_aux *game, t_aux *aux)
{
	int **visited;
	int i;

	i = 0;
	visited = malloc(sizeof(int *) * game->rows);
	while (i < game->rows)
	{
		visited[i] = malloc(sizeof(int) * game->colums);
		i++;
	}
	if (valid_path_helper(game, game->start_x, game->start_y))
	{
		if (valid_coins(aux, aux->start_x, aux->start_y, visited))
			return (1);
	}
	return (0);
}
