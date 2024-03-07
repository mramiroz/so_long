/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:07:26 by mramiro-          #+#    #+#             */
/*   Updated: 2024/03/07 09:28:02 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int	valid_path_helper(t_aux *aux, int x, int y)
{
	if (x < 0 || y < 0 || x >= aux->colums || y >= aux->rows)
		return (0);
	if (aux->map[y][x] == '1')
		return (0);
	if (aux->visited[y][x] == 1)
		return (0);
	if (aux->map[y][x] == 'E' && aux->collectibles == aux->get_colec)
		return (1);
	if (aux->map[y][x] == 'E' && aux->collectibles != aux->get_colec)
	{
		aux->get_exit++;
		return (0);
	}
	if (aux->map[y][x] == 'C')
	{
		aux->get_colec++;
		if (aux->get_exit == 1 && aux->collectibles == aux->get_colec)
			return (1);
	}
	if ((aux->map[y][x] == '0' || aux->map[y][x] == 'P') && aux->visited[y][x] == 0)
	{
		aux->visited[y][x] = 1;
		printf("x: %d, y: %d\n", x, y);
		if (valid_path_helper(aux, x, y - 1) ||
			valid_path_helper(aux, x, y + 1) ||
			valid_path_helper(aux, x - 1, y) ||
			valid_path_helper(aux, x + 1, y))
		{
			return (1);
		}
	}
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

