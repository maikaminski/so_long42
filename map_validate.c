/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:11:14 by makamins          #+#    #+#             */
/*   Updated: 2025/04/08 16:03:33 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	validate_map_tiles(t_game *game, int *p_count)
{
	int		x;
	int		y;
	char	tile;

	y = -1;
	while (++y < game->map_height)
	{
		x = -1;
		while (++x < game->map_width)
		{
			tile = game->map[y][x];
			if (!(
					tile == '0' || tile == '1'
					|| tile == 'C' || tile == 'E'
					|| tile == 'P'))
				exit_error("Invalid char", game);
			if (game->map[y][x] == 'P' && ++(*p_count))
			{
				game->player.x = x;
				game->player.y = y;
			}
			game->exit_count += (game->map[y][x] == 'E');
			game->collectibles += (game->map[y][x] == 'C');
		}
	}
}

static void	validate_map(t_game *game)
{
	int	p_count;

	p_count = 0;
	game->exit_count = 0;
	game->collectibles = 0;
	validate_map_tiles(game, &p_count);
	if (p_count != 1 || game->exit_count != 1 || game->collectibles < 1)
		exit_error("Map needs 1P, 1E, 1C+", game);
}

static void	check_walls(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		if (y == 0 || y == game->map_height - 1)
		{
			x = 0;
			while (x < game->map_width)
			{
				if (game->map[y][x] != '1')
					exit_error("Map must be surrounded by walls", game);
				x++;
			}
		}
		else if (
			game->map[y][0] != '1' ||
			game->map[y][game->map_width - 1] != '1'
				)
			exit_error("Map must be surrounded by walls", game);
		y++;
	}
}

static void	read_map_lines(int fd, t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (i >= MAX_HEIGHT)
			exit_error("Map is too tall", game);
		game->map[i++] = ft_strtrim(line, "\n");
		free(line);
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
	game->map_height = i;
	game->map_width = ft_strlen(game->map[0]);
}

int	parse_map(char *map_file, t_game *game)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		exit_error("Failed to open map file", game);
	game->map = (char **)ft_calloc(MAX_HEIGHT + 1, sizeof(char *));
	if (!game->map)
		exit_error("Memory allocation failed", game);
	read_map_lines(fd, game);
	close(fd);
	validate_map(game);
	check_walls(game);
	validate_path(game);
	return (1);
}
