/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:45:42 by clmanouk          #+#    #+#             */
/*   Updated: 2024/11/12 14:30:42 by clmanouk         ###   ########.fr       */
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
//pour les calculs 
# define TABLE_SIZE 360   // Précision en degrés pour un cercle complet
# define RAD_TO_DEG (180.0 / M_PI) // pour convertir de radian a degres
# define DEG_TO_RAD (M_PI / 180.0) // pour convertir de degres a radian

typedef struct s_data
{
	void		*img_ptr;
	int 		length; // or width
	int			height;
}				t_data;

typedef struct s_player
{
	int			vector_pos[2];
	int			vector_dir;
	int			player_pos;
	int 		*player_dir; // pr WESN du player
	int			x;
	int			y;
	int			south;
	int			west;
	int			north;
	int			est;
}				t_player;

typedef struct s_map
{
	char		**grid;
	int			hit;
	t_player	player;
	t_data		data;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;

}				t_game;

typedef struct s_calcul_table //strcut pour calculer tables des sin, cos, tangentes, fish-eye et angle FOV
{
	float	*sin;
	float	*cos;
	float	*tang;
	float	*fish_eyes;
	float	*calcul_angle_fov;
}			t_calcul_table;

int				get_map(t_map *map, const char *filename);
char			**ft_realloc_map(t_map *map);

#endif