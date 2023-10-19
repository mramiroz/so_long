/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 09:08:09 by mramiro-          #+#    #+#             */
/*   Updated: 2023/10/19 12:35:04 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		perror("Error");
		exit(1);
	}
	if (is_ber(argv[1]) == 0)
	{
		perror("Error");
		exit(1);
	}
	printf("OK");
}
