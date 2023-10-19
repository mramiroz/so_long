/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrarmiro- <mramiro-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:39:02 by mrarmiro-         #+#    #+#             */
/*   Updated: 2023/01/17 16:39:02 by mrarmiro-        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_join(char *s1, char *s2)
{
	char	*aux;

	aux = ft_strjoin(s1, s2);
	if (!aux)
		return (NULL);
	free (s1);
	return (aux);
}
