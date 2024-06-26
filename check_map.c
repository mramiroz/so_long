/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:39:56 by mramiro-          #+#    #+#             */
/*   Updated: 2024/04/23 11:12:32 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*create_map_line(int fd)
{
	char	*line;
	char	*temp;
	char	buffer[2];

	line = malloc(sizeof(char) * 1);
	if (!line)
		ft_error("Line error");
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
		ft_error("It isn't a .ber file");
}

void	is_rectangle(char **lines, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len_double(lines) - 1)
	{
		j = 0;
		if (ft_strlen(lines[i]) != len)
			ft_error_map("It isn't a rectangle", lines);
		while (lines[i][j] != '\0')
		{
			if (lines[i][j] != '1' && (j == 0 || j == len - 1
				|| i == 0 || i == len_double(lines) - 1))
				ft_error_map("It isn't surrounded by walls", lines);
			j++;
		}
		i++;
	}
}

void	scan_map(t_game *game, int len, int start, int end)
{
	int	i;
	int	j;

	i = -1;
	while (++i < len_double(game->map.map))
	{
		j = -1;
		while (++j < len)
		{
			if (game->map.map[i][j] == '0' || game->map.map[i][j] == '1')
				continue ;
			else if (game->map.map[i][j] == 'P')
				start += set_player(game, i, j);
			else if (game->map.map[i][j] == 'E')
				end += set_exit(game, i, j);
			else if (game->map.map[i][j] == 'C')
				game->map.collectibles++;
			else
				ft_error_map("Invalid character", game->map.map);
		}
	}
	if ((end > 1 || start > 1) || (end == 0 && start == 0))
		ft_error_map("Start or End error", game->map.map);
}

void	valid_map(t_game *game, const char *file)
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
		ft_error("Open file error");
	line = create_map_line(fd);
	game->map.map = ft_split(line, '\n');
	if (len_double(game->map.map) != count_n(line) + 1)
		ft_error_map("Invalid map", game->map.map);
	free(line);
	len = ft_strlen(game->map.map[len_double(game->map.map) - 1]);
	is_rectangle(game->map.map, len);
	game->map.rows = len_double(game->map.map);
	game->map.columns = ft_strlen(game->map.map[0]) - 1;
	game->map.collectibles = 0;
	scan_map(game, len, start, end);
}
