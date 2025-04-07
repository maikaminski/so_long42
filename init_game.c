/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:35:33 by makamins          #+#    #+#             */
/*   Updated: 2025/04/07 15:49:47 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*init_game(void)
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
	game->mlx = mlx_init(MAX_WIDTH * TILE_SIZE, MAX_HEIGHT * TILE_SIZE, "so_long", true);
	if (!game->mlx)
	{
		free(game->tex);
		free(game);
		return (NULL);
	}
	game->window = NULL;
	game->map = NULL;
	game->player.x = 0;
	game->player.y = 0;
	game->player.moves = 0;
	game->collectibles = 0;
	game->collected = 0;
	return (game);
}
