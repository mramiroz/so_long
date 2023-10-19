/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrarmiro- <mramiro-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:30:35 by mrarmiro-         #+#    #+#             */
/*   Updated: 2022/10/04 19:30:35 by mrarmiro-        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*pnt;

	if (*lst == 0)
	*lst = new;
	else
	{
		pnt = *lst;
		while (pnt->next)
			pnt = pnt->next;
		pnt->next = new;
	}
}
