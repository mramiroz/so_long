/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 07:55:22 by mramiro-          #+#    #+#             */
/*   Updated: 2023/10/20 10:06:46 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int select_key(int key)
{
	if (key == 53)
		exit(0);
	return (0);
}

int	key_hook(int key, void *param)
{
	t_img *img;

	img = (t_img *)param;
	if (key == KEY_ESC)
	{
		mlx_destroy_window(img->win.id, img->win.win);
		exit(0);
	}
	// else if(key == KEY_A)
	// else if(key == KEY_D)	
	// else if(key == KEY_S)
	// else if(key == KEY_D)
	mlx_put_image_to_window(img->win.id, img->win.win, img->img, 0, 0);
	return (0);
}