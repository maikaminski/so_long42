/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:20:58 by makamins          #+#    #+#             */
/*   Updated: 2025/04/07 18:19:54 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render(t_game *game, int i, int j, mlx_image_t *img)
{
	int	x;
	int	y;
	
	if (!game->mlx || !img)
	{
		ft_printf("Image not found\n");
		return ;
	}
	x = j * TILE_SIZE;
	y = i * TILE_SIZE;
	mlx_image_to_window(game->mlx, img, x, y);
}

void	render_floor(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			render(game, i, j, game->tex->floor);
			j++;
		}
		i++;
	}
}

void	render_w_e_c(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				render(game, i, j, game->tex->wall);
			else if (game->map[i][j] == 'E')
				render(game, i, j, game->tex->exit);
			else if (game->map[i][j] == 'C')
				render(game, i, j, game->tex->coll);
			j++;
		}
		i++;
	}
}

void	render_player(t_game *game)
{
	mlx_t	*mlx;
	int		x;
	int		y;
	
	mlx = game->mlx;
	if (!mlx || !game->tex->player_img)
	{
		ft_printf("Image player not found\n");
		return ;
	}
	x = game->player.x * TILE_SIZE;
	y = game->player.y * TILE_SIZE;
	mlx_image_to_window(mlx, game->tex->player_img, x, y);
	game->current = game->tex->player_img;
}

void	render_all(t_game *game)
{
	render_floor(game);
	render_w_e_c(game);
	render_player(game);
}