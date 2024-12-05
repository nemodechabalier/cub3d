/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:45:42 by clmanouk          #+#    #+#             */
/*   Updated: 2024/12/05 20:33:04 by clmanouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft_all/ft_printf/ft_printf.h"
# include "../libft_all/get_next_line/get_next_line.h"
# include "../libft_all/libtf/libft.h"
# include "../mlx_linux/mlx.h"
# include "parsing.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>
# include <wayland-version.h>

// float 4 octects - double 8 octects
# define FALSE 0
# define TRUE 1
# define FAIL -1
# define SUCCESS 2
# define M_PI 3.14159265358979323846
# define TABLE_SIZE 360
# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600
//# define RAD_TO_DEG (180.0 / M_PI) // pour convertir de radian a degres
# define RAD_TO_DEG (TABLE_SIZE / (2 * M_PI))
# define DEG_TO_RAD (M_PI / 180.0) // pour convertir de degres a radian
# define texWidth 64
# define texHeight 64

typedef struct s_calcul_table	t_calcul_table;
typedef struct s_dda			t_dda;
typedef struct s_game			t_game;
typedef struct s_texture		t_texture;

typedef struct s_player
{
	float						pos_x;
	float						pos_y;
	float						angle;
	float						dir_x;
	float						dir_y;
	float						plane_x;
	float						plane_y;
	double						fov;
	// double						speed;
	t_calcul_table				*table;
	t_dda						*dda;
}								t_player;

typedef struct s_dda
{
	int							map_x;
	int							map_y;
	float						ray_dir_x;
	float						ray_dir_y;
	float						side_dist_x;
	float						side_dist_y;
	float						delta_dist_x;
	float						delta_dist_y;
	int							step_x;
	int							step_y;
	int							hit;
	int							side;
	float						perp_wall_dist;
}								t_dda;

typedef struct s_game
{
	void						*mlx;
	void						*mlx_win;
	t_player					*player;
	t_calcul_table				*table;
	t_texture					*text;
}								t_game;

typedef struct s_texture
{
	void						*img_ptr[3];
	char						*path[3];
	int							width;
	int							height;
	char						*addr[3];
	int							bits_per_pixel;
	int							line_length;
	int							endian;
}								t_texture;

typedef struct s_map
{
	char						**grid;
	char						*addr;
	void						*img_ptr;
	int							length;
	int							height;
	int							bits_per_pixel;
	int							line_length;
	int							endian;
	t_game						*game;
}								t_map;

typedef struct s_calcul_table
{
	float						*sin;
	float						*cos;
	float						*tang;
}								t_calcul_table;

// init
t_player						*ft_init_player(t_calcul_table *table,
									t_player *player);
t_dda							*ft_init_dda(void);
t_calcul_table					*ft_init_calcul(t_calcul_table *table);
t_game							*ft_init_game_data(void);
t_map							*return_value_file(char **file);
t_map							*copy_map(t_map *map, char **file,
									int file_height, int file_length);
t_texture						*ft_init_texture(t_game *game,
									t_texture *texture);

// dda
int								start_algo_dda(t_map *map, t_player *player,
									int x);
int								init_game(t_map *map);
int								render(t_map *map);

// mlx
void							draw_background(t_map *map);
int								move_player(int keycode, t_map *map);
void							draw_game(t_map *map);
void							draw_wall(t_map *map, int *color, int tex_x,
									int tex_y);
void							get_texture_position(t_map *map,
									t_player *player, int x);
void							transpose_text(char **textures, int tex_count);

// free
void							ft_free_map(t_map *map);
int								close_window(t_map *map);
void							ft_free_data(t_game *game);
#endif