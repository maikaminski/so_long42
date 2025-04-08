/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:57:19 by makamins          #+#    #+#             */
/*   Updated: 2025/04/08 18:36:44 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	free_textures(t_game *game)
{
	if (game->tex->floor)
		mlx_delete_image(game->mlx, game->tex->floor);
	if (game->tex->exit)
		mlx_delete_image(game->mlx, game->tex->exit);
	if (game->tex->coll)
		mlx_delete_image(game->mlx, game->tex->coll);
	if (game->tex->p_img)
		mlx_delete_image(game->mlx, game->tex->p_img);
	if (game->tex->wall)
		mlx_delete_image(game->mlx, game->tex->wall);
	if (game->tex->wall_t)
		mlx_delete_texture(game->tex->wall_t);
	if (game->tex->player_t)
		mlx_delete_texture(game->tex->player_t);
	if (game->tex->exit_t)
		mlx_delete_texture(game->tex->exit_t);
	if (game->tex->coll_t)
		mlx_delete_texture(game->tex->coll_t);
	if (game->tex->floor_t)
		mlx_delete_texture(game->tex->floor_t);
	free(game->tex);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->tex)
		free_textures(game);
	if (game->map)
		free_matrix(game->map);
	if (game->mlx)
		mlx_terminate(game->mlx);
	free(game);
}

void	exit_error(char *message, t_game *game)
{
	if (!game)
		return ;
	ft_printf("Error: %s\n", message);
	free_game(game);
	exit(EXIT_FAILURE);
}
