/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrarmiro- <mramiro-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:05:43 by mrarmiro-         #+#    #+#             */
/*   Updated: 2022/10/05 18:05:43 by mrarmiro-        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst)
	{
		while (lst)
		{
			f (lst->content);
			lst = lst->next;
		}
	}
}
