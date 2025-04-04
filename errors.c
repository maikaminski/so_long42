/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:57:19 by makamins          #+#    #+#             */
/*   Updated: 2025/04/04 14:39:06 by makamins         ###   ########.fr       */
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
	if (game->textures->wall)
		mlx_delete_texture(game->textures->wall);
	if (game->textures->player_img)
		mlx_delete_texture(game->textures->player_img);
	if (game->textures->exit)
		mlx_delete_texture(game->textures->exit);
	if (game->textures->collectible)
		mlx_delete_texture(game->textures->collectible);
	free(game->textures);
}

void	free_game(t_game *game)
{
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game->map)
		free_matrix(game->map);
	if (game->textures)
		free_textures(game);
	free(game);
}

void	exit_error(char *message, t_game *game)
{
	ft_printf("Error\n%s\n", message);
	free_game(game);
	exit(EXIT_FAILURE);
}
