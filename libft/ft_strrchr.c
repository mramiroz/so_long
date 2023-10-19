/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:49:04 by mramiro-          #+#    #+#             */
/*   Updated: 2022/09/23 14:16:10 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int		i;
	char	*s;

	i = ft_strlen(str);
	s = (char *)str + i;
	while (i >= 0)
	{
		if (*s == (unsigned char)ch)
		{
			return (s);
		}
	s--;
	i--;
	}
	return (0);
}
