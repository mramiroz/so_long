/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:07:26 by mramiro-          #+#    #+#             */
/*   Updated: 2024/03/06 13:16:52 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	min_visited(t_aux *aux, int x, int y)
{
	int	min;
	int	min_x;
	int	min_y;

	min_x = 0;
	min_y = 0;
	min = INT_MAX;
	if (aux->map[y - 1][x] != '1')
	{
		min = aux->visited[y - 1][x];
		min_x = x;
		min_y = y - 1;
	}
	if (aux->visited[y + 1][x] <= min && aux->map[y + 1][x] != '1')
	{
		min = aux->visited[y + 1][x];
		min_x = x;
		min_y = y + 1;
	}
	if (aux->visited[y][x - 1] <= min && aux->map[y][x - 1] != '1')
	{
		min = aux->visited[y][x - 1];
		min_x = x - 1;
		min_y = y;
	}
	if (aux->visited[y][x + 1] <= min && aux->map[y][x + 1] != '1')
	{
		min = aux->visited[y][x + 1];
		min_x = x + 1;
		min_y = y;
	}
	aux->visited[min_y][min_x]++;
	if (min == INT_MAX)
		return (0);
	if (valid_path_helper(aux, min_x, min_y))
		return (1);
	return (0);
}

int	valid_path_helper(t_aux *aux, int x, int y)
{
	if (x < 0 || y < 0 || x >= aux->colums || y >= aux->rows)
		return (0);
	if (aux->map[y][x] == 'E' && aux->get_colec == aux->collectibles)
		return (1);
	if (aux->map[y][x] == 'E' && aux->get_colec != aux->collectibles)
		return (0);
	if (aux->map[y][x] == '1')
		return (0);
	if (aux->map[y][x] == 'C')
		aux->get_colec++;
	aux->map[y][x] = '0';
	if (min_visited(aux, x, y))
		return (1);
	return (0);
}

int	valid_path(t_aux *aux)
{
	int	x;
	int	y;

	y = 0;
	aux->visited = malloc(sizeof(int) * aux->rows);
	if (!aux->visited)
		ft_error("Allocate failure");
	while (y < aux->colums)
	{
		aux->visited[y] = malloc(sizeof(int) * aux->colums);
		if (!aux->visited[y])
			ft_error("Allocate failure");
		x = 0;
		while (x < aux->colums)
		{
			aux->visited[y][x] = 0;
			x++;
		}
		y++;
	}
	if (valid_path_helper(aux, aux->start_x, aux->start_y))
		return (1);
	return (0);
}

