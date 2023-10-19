/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrarmiro- <mramiro-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:35:59 by mrarmiro-         #+#    #+#             */
/*   Updated: 2022/10/05 17:35:59 by mrarmiro-        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;

	if (!lst || !del)
		return ;
	if (lst)
	{
		while (*lst)
		{
			node = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = node;
		}
	}
}
