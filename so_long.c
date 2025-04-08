/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:38:41 by makamins          #+#    #+#             */
/*   Updated: 2025/04/08 16:16:50 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_game(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	free_game(game);
	exit(EXIT_SUCCESS);
}

void	render_all(t_game *game)
{
	render_floor(game);
	render_exit_tile(game);
	render_w_e_c(game);
	render_player(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		exit_error("Usage: ./so_long <map_file.ber>", NULL);
	game = init_game(argv[1]);
	if (!game)
		exit_error("Failed to initialize game", NULL);
	load_textures(game);
	load_images(game);
	render_all(game);
	mlx_key_hook(game->mlx, &handle_keypress, game);
	mlx_close_hook(game->mlx, close_game, game);
	mlx_loop(game->mlx);
	return (0);
}
