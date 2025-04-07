/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:38:41 by makamins          #+#    #+#             */
/*   Updated: 2025/04/07 17:54:43 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"


int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		exit_error("Usage: ./so_long <map_file.ber>", NULL);
	game = init_game();
	if (!parse_map(argv[1], game))
		exit_error("Map parsing failed", game);
	load_textures(game);
	load_images(game);
	render_all(game);
	mlx_key_hook(game->mlx, &handle_keypress, game);
	mlx_loop(game->mlx);
	free_game(game);
	return (0);
}
