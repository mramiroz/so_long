/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:09:47 by mramiro-          #+#    #+#             */
/*   Updated: 2022/10/18 12:02:03 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int x, size_t n)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)ptr;
	while (i < n)
		((unsigned char *)s)[i++] = (unsigned char)x;
	return (ptr);
}

/*
int main()
{
	char str[] = "Hola buenas";
	ft_memset(str, 'c', 3); 
	printf("%s", str);
}
*/