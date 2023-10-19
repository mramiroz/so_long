/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:49:41 by mramiro-          #+#    #+#             */
/*   Updated: 2022/10/12 15:10:48 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	len_dest;
	size_t	i;
	size_t	len;
	size_t	n;

	if (dstsize == 0)
		return (ft_strlen(src));
	n = 0;
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	len = len_dest + len_src;
	i = 0;
	if (dstsize <= len_dest)
		return (len_src + dstsize);
	while (dest[n])
		n++;
	while ((n < dstsize - 1) && src[i])
	{
		dest[n] = src[i];
		i++;
		n++;
	}
	dest[n] = '\0';
	return (len);
}
