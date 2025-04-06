#include "so_long.h"

void	render_floor(t_game *game, int x, int y)
{
	mlx_image_t	*floor_img;

	floor_img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	if (!floor_img)
		exit_error("Failed to create floor image", game);
	mlx_image_to_window(game->mlx, floor_img, x * TILE_SIZE, y *TILE_SIZE);
}

void	render_all_floors(t_game *game)
{
	int y;
	int x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] != '1')
				render_floor(game, x, y);
			x++;
		}
		y++;
	}
}

void	render_wall(t_game *game, int x, int y)
{
	mlx_image_t	*wall_img;

	wall_img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	if (!wall_img)
		exit_error("Failed to create wall image", game);
	mlx_image_to_window(game->mlx, wall_img, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_all_walls(t_game *game)
{
	int y;
	int x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == '1')
				render_wall(game, x, y);
			x++;
		}
		y++;
	}
}
