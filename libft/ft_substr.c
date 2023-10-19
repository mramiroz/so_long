/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 23:14:50 by marvin            #+#    #+#             */
/*   Updated: 2022/09/23 23:14:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if ((unsigned int)ft_strlen(s) <= start)
		len = 0;
	if ((ft_strlen(s) - start) < len)
		len = ft_strlen(s) - start;
	d = ft_calloc((len + 1), sizeof(*s));
	if (!d)
		return (0);
	while (len > i)
		d[i++] = (char)s[start++];
	return (d);
}
