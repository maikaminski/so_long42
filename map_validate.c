#include "so_long.h"

static int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'P' || c == 'E' || c == 'C');
}

static void	validate_map(t_game *game)
{
	int	y;
	int	x;
	int	p_count;
	int	e_count;
	int	c_count;

	y = -1;
	p_count = 0;
	e_count = 0;
	c_count = 0;
	while (++y < game->map_height)
	{
		x = -1;
		while (++x < game->map_width)
		{
			if (!is_valid_char(game->map[y][x]))
				exit_error("Invalid character in map", game);
			if (game->map[y][x] == 'P')
			{
				game->player.x = x;
				game->player.y = y;
				p_count++;
			}
			else if (game->map[y][x] == 'E')
				e_count++;
			else if (game->map[y][x] == 'C')
				c_count++;
		}
	}
	if (p_count != 1 || e_count != 1 || c_count < 1)
		exit_error("Map must have 1 Player, 1 Exit, and at least 1 Collectible", game);
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