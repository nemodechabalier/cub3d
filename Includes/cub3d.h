/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:45:42 by clmanouk          #+#    #+#             */
/*   Updated: 2024/11/19 18:55:43 by clmanouk         ###   ########.fr       */
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

# define FALSE 0
# define TRUE 1
# define FAIL -1
# define SUCCESS 2
// pour les calculs
# define M_PI 3.14159265358979323846
# define TABLE_SIZE 360   // Précision en degrés pour un cercle complet
# define SCREEN_WIDTH 800 // Largeur ecran en pixels
# define SCREEN_HEIGHT 600
# define FOV_HORIZONTAL 60
# define FOV_VERTICAL 45
# define RAD_TO_DEG (180.0 / M_PI) // pour convertir de radian a degres
# define DEG_TO_RAD (M_PI / 180.0) // pour convertir de degres a radian

typedef struct s_calcul_table	t_calcul_table;
typedef struct s_dda			t_dda;
typedef struct s_game			t_game;
typedef struct s_img			t_img;

typedef struct s_img
{
	void						*img_ptr;
	int							length;
	int							height;
}								t_img;

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
	double						*camera_x;
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
	float						perp_wall_dist;
	t_player					*player;
}								t_dda;

typedef struct s_game
{
	void						*mlx;
	void						*mlx_win;
	t_img						img;
}								t_game;

typedef struct s_map
{
	char						**grid;
	int							hit;
	t_game						game;
}								t_map;

typedef struct s_calcul_table
{
	float						*sin;
	float						*cos;
	float						*tang;
	float						*fish_eyes;
}								t_calcul_table;

// init
int								ft_init_player(t_player *player,
									t_calcul_table *table);
t_dda							*ft_init_dda(t_player *player);
t_calcul_table					*ft_init_calcul(t_player *player,
									t_calcul_table *table);

// dda
int								start_algo_dda(t_dda *dda, t_file *file);

// mlx
int								mlx_init_first(t_map *map);
void							draw_background(t_map *map);
int								move_player(int keycode, t_player *player);

t_map							*start_map(char **file);
void							mlx_function_call(t_map *map, t_file *file);
void							ft_free_map(char **map);
int								close_window(t_map *map);

#endif