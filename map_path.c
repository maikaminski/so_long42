/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:43:57 by makamins          #+#    #+#             */
/*   Updated: 2025/04/08 18:45:25 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_map_copy(char **copy)
{
	int	i;

	i = 0;
	while (copy[i])
		free(copy[i++]);
	free(copy);
}

static void	ft_flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	ft_flood_fill(map, x + 1, y);
	ft_flood_fill(map, x - 1, y);
	ft_flood_fill(map, x, y + 1);
	ft_flood_fill(map, x, y - 1);
}

static char	**copy_map(char **map, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	check_reachable(t_game *game, char **map_copy, int *c, int *e)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)
		{
			if (game->map[i][j] == 'C' && map_copy[i][j] == 'F')
				(*c)++;
			if (game->map[i][j] == 'E' && map_copy[i][j] == 'F')
				*e = 1;
		}
	}
}

void	validate_path(t_game *game)
{
	char	**map_copy;
	int		c_count;
	int		e_found;

	map_copy = copy_map(game->map, game->map_height);
	if (!map_copy)
		exit_error("Map copy failed", game);
	ft_flood_fill(map_copy, game->player.x, game->player.y);
	c_count = 0;
	e_found = 0;
	check_reachable(game, map_copy, &c_count, &e_found);
	free_map_copy(map_copy);
	if (c_count != game->collectibles || !e_found)
		exit_error("Not all collectibles or exit are reachable", game);
}
