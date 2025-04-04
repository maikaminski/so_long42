/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:11:14 by makamins          #+#    #+#             */
/*   Updated: 2025/04/04 14:24:32 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'P' || c == 'E' || c == 'C');
}

static void validate_map(t_game *game)
{
    int y = -1;
    int x;
    int p_count = 0;

    game->exit_count = 0;
    game->collectibles = 0;
    while (++y < game->map_height && (x = -1))
        while (++x < game->map_width)
        {
            if (!is_valid_char(game->map[y][x]))
                exit_error("Invalid char", game);
            if (game->map[y][x] == 'P' && ++p_count)
            {
                game->player.x = x;
                game->player.y = y;
            }
            game->exit_count += (game->map[y][x] == 'E');
            game->collectibles += (game->map[y][x] == 'C');
        }
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
		else if (game->map[y][0] != '1' || game->map[y][game->map_width - 1] != '1')
			exit_error("Map must be surrounded by walls", game);
		y++;
	}
}

int	parse_map(char *map_file, t_game *game)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		exit_error("Failed to open map file", game);
	game->map = (char **)ft_calloc(MAX_HEIGHT + 1, sizeof(char *));
	if (!game->map)
		exit_error("Memory allocation failed", game);
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (i >= MAX_HEIGHT)
			exit_error("Map is too tall", game);
		game->map[i++] = ft_strtrim(line, "\n");
		free(line);
	}
	close(fd);
	game->map_height = i;
	game->map_width = ft_strlen(game->map[0]);
	validate_map(game);
	check_walls(game);
	return (1);
}
