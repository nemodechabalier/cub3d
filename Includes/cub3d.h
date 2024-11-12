/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:45:42 by clmanouk          #+#    #+#             */
/*   Updated: 2024/11/12 17:41:19 by clmanouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft_all/ft_printf/ft_printf.h"
# include "../libft_all/get_next_line/get_next_line.h"
# include "../libft_all/libtf/libft.h"
# include "mlx_linux/mlx.h"
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
# define TABLE_SIZE 360            // Précision en degrés pour un cercle complet
# define RAD_TO_DEG (180.0 / M_PI) // pour convertir de radian a degres
# define DEG_TO_RAD (M_PI / 180.0) // pour convertir de degres a radian

/*
	int			vector_pos[2];
	int			vector_dir;
	int			player_pos;
	int *player_dir; // pr WESN du player
	a rajouter peut-etre au player
*/
typedef struct s_player
{
	int				x;
	int				y;
	int				angle;
	int				fov;
	int				*player_dir;
	t_calcul_table	*table;
}					t_player;

typedef struct s_dda
{
	int				map_x;
	int				map_y;
	double 			ray_dir_x;
	double			ray_dir_y;
	float			side_dist_x;
	float			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	int				step_x;
	int				step_y;
	int				hit;
	float			perp_wall_dist;
	t_player		*player;
}					t_dda;

typedef struct s_map
{
	char			**grid;
	int				hit;
	int				length;
	int				height;
	t_player		player;
}					t_map;

typedef struct s_game
{
	void			*mlx;
	void			*mlx_win;

}					t_game;

typedef struct s_calcul_table
{
	float			*sin;
	float			*cos;
	float			*tang;
	float			*fish_eyes;
	float			*calcul_angle_fov;
}					t_calcul_table;

int					get_map(t_map *map, const char *filename);
char				**ft_realloc_map(t_map *map);

#endif