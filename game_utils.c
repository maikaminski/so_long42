/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:03:13 by makamins          #+#    #+#             */
/*   Updated: 2025/04/04 16:51:25 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

load_textures();

void	render_all(t_game *game)
{
	render_all_floors(game);
	render_all_walls(game);
	render_all_collectibles(game);
	render_exit(game);
	render_player(game);
}