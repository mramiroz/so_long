/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:14:26 by mramiro-          #+#    #+#             */
/*   Updated: 2022/10/12 13:21:40 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*sstr1;
	unsigned char	*sstr2;

	if (!str1 && !str2)
		return (0);
	i = 0;
	sstr1 = (unsigned char *)str1;
	sstr2 = (unsigned char *)str2;
	if (sstr1 > sstr2)
	{
		while (n-- > 0)
			sstr1[n] = sstr2[n];
	}
	else
	{
		while (i < n)
		{
			sstr1[i] = sstr2[i];
			i++;
		}
	}
	return (sstr1);
}

/*
int main()
{
	char	src[] = "lorem ipsum dolor sit amet";
	char	*d;

	d = src;
	printf("%s", ft_memmove(d, src, 3));
}
*/