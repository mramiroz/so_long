/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:39:56 by mramiro-          #+#    #+#             */
/*   Updated: 2023/10/20 10:29:07 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_ber(const char *file)
{
	const char	*extension;
	int			len;
	int			len_ber;

	extension = ".ber";
	len = ft_strlen(file);
	len_ber = ft_strlen(extension);
	if (ft_strncmp(file + len - len_ber, extension, len_ber) != 0)
		ft_error("No es un archivo .ber");
}

void	is_square(char **lines, int len)
{
	int	i;

	i = 0;
	while (i < len_double(lines) - 1)
	{
		if (ft_strlen(lines[i]) != len)
			ft_error("No es un rectangulo");
		i++;
	}
}

void	scan_map(char **lines, int len, int start, int end)
{
	int	i;
	int	j;

	i = 0;
	while (i < len_double(lines))
	{
		j = 0;
		while (j < len)
		{
			if (lines[i][j] != '1' && (j == 0 || j == len - 1 ||
				i == 0 || i == len_double(lines)))
				ft_error("No esta cerrado por muros");
			if (lines[i][j] == 'P')
				start++;
			if (lines[i][j] == 'E')
				end++;
			if (end > 1 || start > 1)
				ft_error("Hay mas de un inicio o final");
			j++;
		}
		i++;
	}
	if (end == 0 || start == 0)
		ft_error("No hay inicio o final");
}

char	**valid_map(const char *file)
{
	int		fd;
	char	**lines;
	int		len;
	int		start;
	int		end;

	start = 0;
	end = 0;
	is_ber(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	lines = ft_split(get_next_line(fd), '\n');
	len = ft_strlen(lines[len_double(lines) - 1]);
	is_square(lines, len + 1);
	scan_map(lines, len, start, end);
	printf("OK");
	return (lines);
}
