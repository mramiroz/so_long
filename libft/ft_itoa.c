/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrarmiro- <mramiro-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:26:35 by mrarmiro-         #+#    #+#             */
/*   Updated: 2022/09/29 15:26:35 by mrarmiro-        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	cuenta_digitos(int i)
{
	int	n;

	n = 0;
	if (i < 0)
	{
		i = -i;
		n++;
	}
	while (i >= 10)
	{
		i = i / 10;
		n++;
	}
	if (i < 10)
		n++;
	return (n);
}

char	*ft_itoa(int value)
{
	int		i;
	char	*str;
	int		size;

	i = 0;
	size = cuenta_digitos(value);
	if (value == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (value == 0)
		str[i] = '0';
	if (value < 0)
	{
		str[i++] = '-';
		value = -value;
	}
	while (value > 0)
	{
		str[--size] = value % 10 + '0';
		value = value / 10;
	}
	return (str);
}
