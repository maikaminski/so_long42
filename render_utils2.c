#include "so_long.h"

void	render_player(t_game *game)
{
	mlx_image_t	*player_img;

	player_img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	if (!player_img)
		exit_error("Failed to create player image", game);
	mlx_image_to_window(game->mlx, player_img, game->player.x * TILE_SIZE, game->player.y * TILE_SIZE);
}

void	render_exit(t_game *game)
{
	mlx_image_t	*exit_img;
	int			y;
	int			x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'E')
			{
				exit_img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
				if (!exit_img)
					exit_error("Failed to create exit image" game);
				mlx_image_to_window(game->mlx, exit_img, x *TILE_SIZE, y *TILE_SIZE);
			}
			x++;
		}
		y++;
	}
}

void	render_collectible(t_game *game, int x, int y)
{
	mlx_image_t	*collectible_img;

	collectible_img = mlx_new_image(game->mlx,TILE_SIZE, TILE_SIZE);
	if (!collectible_img)
		exit_error("Failed to create collectible image", game);
	mlx_image_to_window(game->mlx, collectible_img, x *TILE_SIZE, y * TILE_SIZE);
}

void	render_all_collectibles(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'C')
				render_collectible(game, x, y);
			x++;
		}
		y++;
	}
}