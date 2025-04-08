/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:42:21 by makamins          #+#    #+#             */
/*   Updated: 2025/04/08 18:56:32 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_move(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->map_width || y >= game->map_height)
		return (0);
	if (game->map[y][x] == 'E' && game->collected != game->collectibles)
		return (0);
	if (game->map[y][x] == '1')
		return (0);
	return (1);
}

static void	move_to_tile(t_game *game, int new_x, int new_y)
{
	render(game, game->player.y, game->player.x, game->tex->floor);
	if (game->map[game->player.y][game->player.x] != 'E')
		game->map[game->player.y][game->player.x] = '0';
	if (game->map[new_y][new_x] != 'E')
		game->map[new_y][new_x] = 'P';
	game->player.x = new_x;
	game->player.y = new_y;
	game->player.moves++;
	render_player(game);
	ft_printf("Moves: %d\n", game->player.moves);
}

static void	update_player_position(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'C')
		game->collected++;
	if (game->map[new_y][new_x] == 'E' && game->collected == game->collectibles)
	{
		ft_printf("You win! Moves: %d\n", game->player.moves);
		free_game(game);
		exit(EXIT_SUCCESS);
	}
	move_to_tile(game, new_x, new_y);
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player.x + dx;
	new_y = game->player.y + dy;
	if (is_valid_move(game, new_x, new_y))
		update_player_position(game, new_x, new_y);
}

void	handle_keypress(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_PRESS)
		move_player(game, 0, -1);
	else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_PRESS)
		move_player(game, 0, 1);
	else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_PRESS)
		move_player(game, -1, 0);
	else if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS)
		move_player(game, 1, 0);
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		free_game(game);
		exit(EXIT_SUCCESS);
	}
}
