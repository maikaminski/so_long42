/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:13:03 by makamins          #+#    #+#             */
/*   Updated: 2025/04/04 16:49:57 by makamins         ###   ########.fr       */
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
# define MAX_HEIGHT 10

typedef struct s_player
{
	int		x;
	int		y;
	int		moves;
}	t_player;

typedef struct s_images
{
    mlx_image_t     *player_img;
    mlx_image_t     *collectible;
    mlx_image_t     *floor;
    mlx_image_t     *wall;
    mlx_image_t     *exit;
    mlx_texture_t   *wall_tex;
    mlx_texture_t   *player_tex;
    mlx_texture_t   *exit_tex;
    mlx_texture_t   *collectible_tex;
} t_images;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	char		**map;
	int			map_height;
	int			map_width;
	int			collectibles;
	int			collected;
	int			exit_count;
	t_images	*textures;
	t_player	player;
	t_images	images;
	int			is_mlx_init;
}	t_game;

void	free_matrix(char **matrix);
void	free_textures(t_game *game);
void	free_game(t_game *game);
void	exit_error(char *message, t_game *game);
void	load_textures(t_game *game);
void	render_map(t_game *game);
t_game	*init_game(void);
int	parse_map(char *map_file, t_game *game);
void	move_player(t_game *game, int dx, int dy);
void	handle_keypress(mlx_key_data_t keydata, void *param);

#endif