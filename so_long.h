/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:13:03 by makamins          #+#    #+#             */
/*   Updated: 2025/04/07 18:20:00 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include "./gnl/get_next_line.h"
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
    mlx_image_t     *coll;
    mlx_image_t     *floor;
    mlx_image_t     *wall;
    mlx_image_t     *exit;
    mlx_texture_t   *wall_tex;
    mlx_texture_t   *player_tex;
    mlx_texture_t   *exit_tex;
    mlx_texture_t   *coll_tex;
	mlx_texture_t	*floor_tex;
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
	mlx_image_t	*current;
	t_images	*tex;
	t_player	player;
	t_images	images;
	int			is_mlx_init;
}	t_game;

void	free_matrix(char **matrix);
void	free_textures(t_game *game);
void	free_game(t_game *game);
void	exit_error(char *message, t_game *game);

void	load_textures(t_game *game);
void	load_images(t_game *game);
void	render(t_game *game, int i, int j, mlx_image_t *img);
void	render_floor(t_game *game);
void	render_w_e_c(t_game *game);
void	render_player(t_game *game);
void	render_all(t_game *game);



t_game	*init_game(void);
int	parse_map(char *map_file, t_game *game);
void	move_player(t_game *game, int dx, int dy);
void	handle_keypress(mlx_key_data_t keydata, void *param);

#endif