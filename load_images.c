/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:03:13 by makamins          #+#    #+#             */
/*   Updated: 2025/04/07 17:50:02 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_game *game)
{
	game->tex->floor_tex = mlx_load_png("./images/grass.png");
	game->tex->exit_tex = mlx_load_png("./images/castle.png");
	game->tex->coll_tex = mlx_load_png("./images/star.png");
	game->tex->player_tex = mlx_load_png("./images/player.png");
	game->tex->wall_tex = mlx_load_png("./images/brick.png");
	if (!game->tex->floor_tex || !game->tex->exit_tex
		|| !game->tex->coll_tex || !game->tex->player_tex || !game->tex->wall_tex)
		exit_error("Failed to load textures", game);
	
}

void	load_images(t_game *game)
{
	game->tex->floor = mlx_texture_to_image(game->mlx, game->tex->floor_tex);
	game->tex->exit = mlx_texture_to_image(game->mlx, game->tex->exit_tex);
	game->tex->coll = mlx_texture_to_image(game->mlx, game->tex->coll_tex);
	game->tex->player_img = mlx_texture_to_image(game->mlx, game->tex->player_tex);
	game->tex->wall = mlx_texture_to_image(game->mlx, game->tex->wall_tex);
	if (!game->tex->floor || !game->tex->exit
		|| !game->tex->coll || !game->tex->player_img || !game->tex->wall)
		exit_error("Failed to load images", game);
}

