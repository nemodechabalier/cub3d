/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:41:28 by nde-chab          #+#    #+#             */
/*   Updated: 2024/12/16 16:56:59 by clmanouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

typedef struct s_calcul_table	t_calcul_table;
typedef struct s_dda			t_dda;
typedef struct s_game			t_game;
typedef struct s_img			t_img;

typedef struct s_file
{
	char						*texture[5];
	char						*rgb[3];
	char						**map;
	int							f[3];
	int							c[3];
}								t_file;

// pars map && texture
t_file							*cut_file(char **strs);
t_file							*verrif_texture(t_file *file, char **strs);
t_file							*take_file(char *file_name);
int								map_verrif(t_file *file);
t_file							*rgb_verrif(t_file *file, char **strs);
char							*rgb_cut(char *str);
char							*alloc_texture(char *str);

// struct
t_file							*t_file_creator(void);
void							file_dest(t_file *file, int bool);

// utils
int								is_map(char *str);
int								ft_empty(char *str);
int								count_word(char const *s, char c);
int								count_alloc_texture(char *str);

// free utils
void							free_strs(char **strs, int bool);
void							print_strs(char **strs);
void							free_file(char **strs);

#endif