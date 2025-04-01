/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:35:33 by makamins          #+#    #+#             */
/*   Updated: 2025/04/01 17:21:47 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*init_game(void)
{
	t_game	*game;
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->mlx = mlx_init(MAX_WIDTH * TILE_SIZE, MAX_HEIGTH * TILE_SIZE, "so_long", true);
	if (!game->mlx)
	{
		FUNCAODEFREE(game);
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