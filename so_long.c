/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:38:41 by makamins          #+#    #+#             */
/*   Updated: 2025/04/04 16:38:42 by makamins         ###   ########.fr       */
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
	render_map(game);
	mlx_key_hook(game->mlx, &handle_keypress, game);
	mlx_loop(game->mlx);
	free_game(game);
	return (0);
}

// void key_hook(mlx_key_data_t keydata, void *mlx)
// {
//     if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
//     {
//         mlx_terminate(mlx);
//         exit(EXIT_SUCCESS);
//     }
// }

// int main(void)
// {
//     mlx_t *mlx = mlx_init(800, 600, "so_long", true);
//     if (!mlx)
//     {
//         fprintf(stderr, "Erro ao iniciar MLX42\n");
//         return EXIT_FAILURE;
//     }

//     // Hook para capturar teclas
//     mlx_key_hook(mlx, key_hook, mlx);

//     // Mantém a janela aberta
//     mlx_loop(mlx);

//     mlx_terminate(mlx);
//     return EXIT_SUCCESS;
// }