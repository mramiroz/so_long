/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:39:56 by mramiro-          #+#    #+#             */
/*   Updated: 2023/10/23 11:06:20 by mramiro-         ###   ########.fr       */
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

int  set_player(t_game *game, int i, int j)
{
	game->player.x = j;
	game->player.y = i;
	return (1);
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

void	scan_map(t_game *game, int len, int start, int end)
{
	int	i;
	int	j;

	i = 0;
	while (i < len_double(game->map.map))
	{
		j = 0;
		while (j < len)
		{
			if (game->map.map[i][j] != '1' && (j == 0 || j == len - 1 ||
				i == 0 || i == len_double(game->map.map) - 1))
				ft_error("No esta cerrado por muros");
			else if (game->map.map[i][j] == 'P')
				start += set_player(game, i, j);
			else if (game->map.map[i][j] == 'E')
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

void	valid_map(t_game *game, const char *file)
{
	int		fd;
	int		len;
	int		start;
	int		end;

	start = 0;
	end = 0;
	is_ber(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("Error al abrir el archivo");
	game->map.map = ft_split(get_next_line(fd), '\n');
	len = ft_strlen(game->map.map[len_double(game->map.map) - 1]);
	is_square(game->map.map, len + 1);
	scan_map(game, len, start, end);
}
