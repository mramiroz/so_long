/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrarmiro- <mramiro-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:15:47 by mrarmiro-         #+#    #+#             */
/*   Updated: 2023/10/19 19:15:47 by mrarmiro-        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_char(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

t_img	create_img(t_win win, int w, int h)
{
	t_img	img;

	img.win = win;
	img.img = mlx_new_image(win.id, w, h);
	img.addr = mlx_get_data_addr(img.img, &img.bpp,
			&img.line_length, &img.endian);
	img.width = w;
	img.height = h;
	return (img);
}

int	len_double(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void zero_map(t_aux *aux, char visited[aux->rows][aux->colums])
{
	int i;
	int j;

	i = 0;

	while (i < aux->rows)
	{
		j = 0;
		while (j < aux->colums)
		{
			visited[i][j] = '0';
			j++;
		}
		i++;
	}
}
