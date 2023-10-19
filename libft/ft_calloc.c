/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:22:44 by mramiro-          #+#    #+#             */
/*   Updated: 2022/10/18 12:01:38 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t num, size_t size)
{
	void	*s;
	int		len;

	len = num * size;
	s = malloc (len);
	if (!s || (len && (len / size != num)))
		return (0);
	ft_bzero(s, size * num);
	return (s);
}
