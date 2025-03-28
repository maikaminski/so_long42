/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:13:03 by makamins          #+#    #+#             */
/*   Updated: 2025/03/28 14:53:50 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"


typedef struct s_player
{
	int		x;
	int		y;
	int		moves;
}	t_player;

typedef struct s_images
{
	void	*player_img;
	void	*collectible;
	void	*floor;
	void	*wall;
	void	*exit;
}	t_images;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	char		**map;
	int			map_height;
	int			map_width;
	t_player	player;
	t_images	images;
}	t_game;

#endif