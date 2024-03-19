/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:07:26 by mramiro-          #+#    #+#             */
/*   Updated: 2024/03/19 20:37:50 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_int(t_aux *aux)
{
    int y;
    
    y = 0;
    while (y < aux->rows)
    {
        free(aux->visited[y]);
        y++;
    }
    free(aux->visited);
}
int	compare_visited(t_aux *aux)
{
	int y;
	int x;
	int count;

	y = 0;
	count = 0;
	while (y < aux->rows)
	{
		x = 0;
		while (x < aux->colums)
		{
			printf("%d", aux->visited[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	return (count);
}
int	valid_path_helper(t_aux *aux, int x, int y)
{
	if (aux->map[y][x] == '1' || aux->visited[y][x] == 1)
		return (0);
	printf("Colec: %d\n", aux->collectibles);
	printf("Get_colec: %d\n", aux->get_colec);
	printf("Get_exit: %d\n", aux->get_exit);
	if (aux->map[y][x] == 'E')
	{
		aux->get_exit++;
		if (aux->collectibles == aux->get_colec)
			return (1);
	}
	if (aux->map[y][x] == 'C')
	{
		aux->get_colec++;
		aux->map[y][x] = '0';
		if (aux->collectibles == aux->get_colec && aux->get_exit == 1)
			return (1);
	}
	aux->visited[y][x]++;
	if (valid_path_helper(aux, x + 1, y) || valid_path_helper(aux, x - 1, y)
		|| valid_path_helper(aux, x, y + 1) || valid_path_helper(aux, x, y - 1))
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
	while (y < aux->rows)
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

