/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:35:33 by makamins          #+#    #+#             */
/*   Updated: 2025/04/08 18:32:35 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_game	*allocate_game(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->tex = (t_images *)malloc(sizeof(t_images));
	if (!game->tex)
	{
		free(game);
		return (NULL);
	}
	return (game);
}

void	setup_game_fields(t_game *game)
{
	game->mlx = NULL;
	game->window = NULL;
	game->map = NULL;
	game->player.x = 0;
	game->player.y = 0;
	game->player.moves = 0;
	game->collectibles = 0;
	game->collected = 0;
	game->tex->floor = 0;
	game->tex->floor_t = 0;
	game->tex->coll = 0;
	game->tex->coll_t = 0;
	game->tex->exit = 0;
	game->tex->exit_t = 0;
	game->tex->p_img = 0;
	game->tex->player_t = 0;
	game->tex->wall = 0;
	game->tex->wall_t = 0;
}

static int	finalize_game_init(t_game *game, char *map_file)
{
	if (!parse_map(map_file, game))
		return (0);
	game->mlx = mlx_init(
			game->map_width * TILE_SIZE,
			game->map_height * TILE_SIZE,
			"so_long", true);
	if (!game->mlx)
		return (0);
	return (1);
}

t_game	*init_game(char *map_file)
{
	t_game	*game;

	game = allocate_game();
	if (!game)
		return (NULL);
	setup_game_fields(game);
	if (!finalize_game_init(game, map_file))
	{
		free_game(game);
		return (NULL);
	}
	return (game);
}
