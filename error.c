/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:13:57 by mramiro-          #+#    #+#             */
/*   Updated: 2024/03/06 12:12:52 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str)
{
	perror(str);
	exit(1);
}

void	ft_error_map(char *str, char **map)
{
	free_map_char(map);
	perror(str);
	exit(1);
}
