/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:57:19 by makamins          #+#    #+#             */
/*   Updated: 2025/04/07 15:43:17 by makamins         ###   ########.fr       */
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
	if (game->tex->wall_tex)
		mlx_delete_texture(game->tex->wall_tex);
	if (game->tex->player_tex)
		mlx_delete_texture(game->tex->player_tex);
	if (game->tex->exit_tex)
		mlx_delete_texture(game->tex->exit_tex);
	if (game->tex->coll_tex)
		mlx_delete_texture(game->tex->coll_tex);
	if (game->tex->floor_tex)
		mlx_delete_texture(game->tex->floor_tex);
	free(game->tex);
}

void	free_game(t_game *game)
{
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game->map)
		free_matrix(game->map);
	if (game->tex)
		free_textures(game);
	free(game);
}

void	exit_error(char *message, t_game *game)
{
	ft_printf("Error\n%s\n", message);
	free_game(game);
	exit(EXIT_FAILURE);
}
