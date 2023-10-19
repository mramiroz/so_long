/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrarmiro- <mramiro-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 10:45:14 by mrarmiro-         #+#    #+#             */
/*   Updated: 2023/01/22 10:45:14 by mrarmiro-        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 10000

# endif

int		searchn(char *c);
char	*get_next_line(int fd);
char	*ft_join(char *s1, char *s2);

#endif