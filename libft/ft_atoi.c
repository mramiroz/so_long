/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 09:41:46 by marvin            #+#    #+#             */
/*   Updated: 2022/09/22 09:41:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

size_t	ft_atoi(const char *str)
{
	int		i;
	long	num;
	int		rest;

	i = 0;
	rest = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45)
		rest *= -1;
	if (str[i] == 45 || str[i] == 43)
		i++;
	while (ft_isdigit(str[i]))
	{
		if ((num * rest) > INT_MAX)
			return (-1);
		else if ((num * rest) < INT_MIN)
			return (0);
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return (num * rest);
}

/*
int main()
{
	printf("%d", ft_atoi("   --\n-+--+1234ab567"));
}
*/