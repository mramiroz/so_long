/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:07:26 by mramiro-          #+#    #+#             */
/*   Updated: 2024/03/20 08:53:05 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	compare_visited(char **map, t_aux *aux)
{
	int y;
	int x;

	y = 0;
	while (y < aux->rows)
	{
		x = 0;
		while (x <= aux->colums)
		{
			printf("%c", map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}
int	valid_path_helper(t_aux *aux, int x, int y)
{
	if (aux->map[y][x] == '1')
		return (0);
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
	aux->map[y][x] = '1';
	if ((x + 1 < aux->colums && valid_path_helper(aux, x + 1, y))
		|| (x - 1 >= 0 && valid_path_helper(aux, x - 1, y))
		|| (y + 1 < aux->rows && valid_path_helper(aux, x, y + 1))	
		|| (y - 1 >= 0 && valid_path_helper(aux, x, y - 1)))
		return (1);
	return (0);
}

int	valid_path(t_aux *aux)
{
	if (valid_path_helper(aux, aux->start_x, aux->start_y))
		return (1);
	return (0);
}

