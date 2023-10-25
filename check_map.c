/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:39:56 by mramiro-          #+#    #+#             */
/*   Updated: 2023/10/25 09:14:19 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_player(t_game *game, int i, int j)
{
	game->player.x = j;
	game->player.y = i;
	return (1);
}

char	*create_map_line(int fd)
{
	char	*line;
	char	*temp;
	char	buffer[2];

	line = malloc(sizeof(char) * 1);
	if (!line)
		ft_error("Error al crear la linea");
	line[0] = '\0';
	while (read(fd, buffer, 1) > 0)
	{
		buffer[1] = '\0';
		temp = ft_strjoin(line, buffer);
		free(line);
		line = temp;
	}
	close(fd);
	return (line);
}

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
				end += set_exit(game, i, j);
			else if (game->map.map[i][j] == 'C')
				game->map.collectibles++;
			if (end > 1 || start > 1)
				ft_error("Hay mas de un inicio o final");
			j++;
		}
		i++;
	}
	if (end == 0 || start == 0)
		ft_error("No hay inicio o final");
}

void	valid_map(t_game *game, t_aux *aux, const char *file)
{
	int		fd;
	int		len;
	int		start;
	int		end;
	char	*line;

	start = 0;
	end = 0;
	is_ber(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("Error al abrir el archivo");
	line = create_map_line(fd);
	game->map.map = ft_split(line, '\n');
	free(line);
	len = ft_strlen(game->map.map[len_double(game->map.map) - 1]);
	is_square(game->map.map, len + 1);
	game->map.rows = len_double(game->map.map);
	game->map.columns = ft_strlen(game->map.map[0]) - 1;
	scan_map(game, len, start, end);
	copy_game(game, aux);
	if (!valid_path(aux))
		ft_error("No hay camino");
}
