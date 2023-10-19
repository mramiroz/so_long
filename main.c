/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrarmiro- <mramiro-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 09:08:09 by mramiro-          #+#    #+#             */
/*   Updated: 2023/10/19 19:59:59 by mrarmiro-        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	valid_map(argv[1]);
}
