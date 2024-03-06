/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:07:26 by mramiro-          #+#    #+#             */
/*   Updated: 2024/03/06 12:24:24 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	min_visited(t_aux *aux, int x, int y)
{
	int	min;
	int	min_x;
	int	min_y;
	int	i;

	i = 0;
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
	return (valid_path_helper(aux, min_x, min_y));
}

int	valid_path_helper(t_aux *aux, int x, int y)
{
	if (x < 0 || y < 0 || x >= aux->colums || y >= aux->rows || aux->visited[y][x] > 3)
        return (0);
	if (aux->map[y][x] == '1')
		return (0);
	if (aux->map[y][x] == 'E' && aux->get_colec == aux->collectibles)
		return (1);
	if (aux->map[y][x] == 'E' && aux->get_colec != aux->collectibles)
		return (0);
	if (aux->map[y][x] == '0' || aux->map[y][x] == 'C' || aux->map[y][x] == 'P')
	{
		if (aux->map[y][x] == 'C')
		{
			aux->map[y][x] = '0';
			aux->get_colec++;
		}
        if (aux->map[y][x] == 'P')
            aux->map[y][x] = '0';
		aux->visited[y][x]++;
	}
	// printf("x: %d, y: %d\n", x, y);
	printf("aux->visited[y][x]: %d\n", aux->visited[y][x]);
	// printf("aux->map[y][x]: %c\n", aux->map[y][x]);
	return (min_visited(aux, x, y));
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

