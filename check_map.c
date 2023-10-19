/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrarmiro- <mramiro-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:39:56 by mramiro-          #+#    #+#             */
/*   Updated: 2023/10/19 20:00:20 by mrarmiro-        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_ber(const char *file)
{
	const char	*extension;
	int			len;
	int			len_ber;

	extension = ".ber";
	len = ft_strlen(file);
	len_ber = ft_strlen(extension);
	if (ft_strncmp(file + len - len_ber, extension, len_ber) != 0)
		return (0);
	return (1);
}
int len_double(char **str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

void	is_square(char **lines, int len)
{
	int i;
	
	i = 0;
	while(i < len_double(lines) - 1)
	{
		printf("L1: %i, L2: %i\n", ft_strlen(lines[i]), len);
		if(ft_strlen(lines[i]) != len)
			ft_error("No es un rectangulo");
		i++;
	}
}



char **valid_map(const char *file)
{
	int		fd;
	char	**lines;
	int		len;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	fd = open(file, O_RDONLY);
	if(fd == -1)
		return (0);
	lines = ft_split(get_next_line(fd), '\n');
	len = ft_strlen(lines[len_double(lines) - 1]);
	is_square(lines, len + 1);
	while (i < len_double(lines))
	{
		while(j < len)
		{
			if (lines[i][j] != '1' && ( j== 0 || j == len - 1))
				ft_error("No esta cerrado por muros");
			if (lines[i][j] != '1' && (i == 0 || i == len_double(lines)))
				ft_error("No esta cerrado por muros");
			j++;
		}
		j = 0;
		i++;
	}

	i = 0;
	
	printf("OK");
	return (lines);
}