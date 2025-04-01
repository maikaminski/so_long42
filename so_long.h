/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:13:03 by makamins          #+#    #+#             */
/*   Updated: 2025/04/01 17:20:54 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include "./libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

# define TILE_SIZE 64
# define MAX_WIDTH 25
# define MAX_HEIGTH 10

typedef struct s_player
{
	int		x;
	int		y;
	int		moves;
}	t_player;

typedef struct s_images
{
	mlx_image_t	*player_img;
	mlx_image_t	*collectible;
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*exit;
}	t_images;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	char		**map;
	int			map_height;
	int			map_width;
	int			collectibles;
	int			collected;
	t_player	player;
	t_images	images;
	int			is_mlx_init;
}	t_game;

#endif