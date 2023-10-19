/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:39:56 by mramiro-          #+#    #+#             */
/*   Updated: 2023/10/19 12:41:26 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_ber(const char *file)
{
	const char	*extension;
	int			len;
	int			len_ber;

	extension = ".ber";
	len = ft_strlen(file);
	len_ber = ft_strlen(extension);
	if (ft_strncmp(file + len - len_ber, extension, len_ber) != 0)
		return (0);
	return (1);
}