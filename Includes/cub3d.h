/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:45:42 by clmanouk          #+#    #+#             */
/*   Updated: 2025/01/15 13:12:14 by clmanouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft_all/ft_printf/ft_printf.h"
# include "../libft_all/get_next_line/get_next_line.h"
# include "../libft_all/libtf/libft.h"
# include "../mlx_linux/mlx.h"
# include "parsing.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>
# include <wayland-version.h>

# define FALSE 0
# define TRUE 1
# define FAIL -1
# define SUCCESS 2
# define M_PI 3.14159265358979323846
# define TABLE_SIZE 360
# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600
# define RAD_TO_DEG 57.2957795131
//(TABLE_SIZE / (2 * M_PI))
# define DEG_TO_RAD 0.01745329251
# define TEXWIDTH 256
# define TEXHEIGHT 256
# define CEILING_COLOR1 0x140A0A
# define CEILING_COLOR2 0x101010
# define FLOOR_COLOR 0x101010
# define RECTANGLE_WIDTH 150
# define RECTANGLE_HEIGHT 50
# define MARGE_PLAYER 1.2f

typedef struct s_calcul_table	t_calcul_table;
typedef struct s_dda			t_dda;
typedef struct s_game			t_game;
typedef struct s_texture		t_texture;

typedef enum e_key_press
{
	key_w,
	key_s,
	key_a,
	key_d,
	key_left,
	key_right,
	key_open,
}								t_key_press;

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
	bool						keys[6];
	t_player					*player;
	t_calcul_table				*table;
	t_texture					*text;
}								t_game;

typedef struct s_texture
{
	void						*img_ptr[4];
	char						*path[4];
	int							width;
	int							height;
	char						*addr[4];
	int							bits_per_pixel;
	int							line_length;
	int							endian;
	int							texture_x;
	int							texture_y;
	int							tex_index;
	int							line_height;
	double						wall_x;
	double						step;
	double						texpos;
}								t_texture;

typedef struct s_map
{
	char						**grid;
	char						*addr;
	void						*img_ptr;
	int							color[2];
	int							length;
	int							height;
	int							bits_per_pixel;
	int							line_length;
	int							endian;
	int							flag;
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
									t_player *player, char **file);
t_dda							*ft_init_dda(void);
t_calcul_table					*ft_init_calcul(t_calcul_table *table);
t_game							*ft_init_game_data(char **file);
t_map							*return_value_file(char **file, t_file *files);
t_map							*copy_map(t_map *map, char **file,
									int file_height, t_file *files);
t_texture						*ft_init_texture(t_game *game,
									t_texture *texture);

// dda
int								start_algo_dda(t_map *map, t_player *player,
									int x);
int								init_game(t_map *map, t_file *file);
int								render(t_map *map);

// mlx
void							draw_background(t_map *map);
int								move_player(int keycode, t_map *map);
void							draw_game(t_map *map);
void							draw_wall(t_map *map, int *color, int tex_x,
									int tex_y);
void							get_texture_position(t_map *map,
									t_player *player, int x);
void							draw_minimap(t_map *map, int minimap_size);

// free
void							ft_free_map(t_map *map);
int								close_window(t_map *map);
void							ft_free_data(t_game *game);
t_texture						*texture_constructor(t_file *file);

int								create_color_ceiling(t_file *file);
int								create_color_floor(t_file *file);
void							check_color_recup(t_file *file);

void							ft_rotate_player(t_player *player,
									float rotation_angle,
									t_calcul_table *table);
int								move_player_dir(t_map *map, t_player *player,
									int move_forward);
int								move_player_ad(t_map *map, t_player *player,
									int move_dir);
int								valid_move(double x, double y, t_map *map);

#endif
