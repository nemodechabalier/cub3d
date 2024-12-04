/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:54:52 by clmanouk          #+#    #+#             */
/*   Updated: 2024/12/04 11:29:48 by clmanouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	draw_game(t_map *map)
{
	int	x;

	x = 0;
	draw_background(map);
	while (x < SCREEN_WIDTH)
	{
		start_algo_dda(map, map->game->player, x);
		//draw_wall(map, x);
		get_texture_position(map, map->game->player, x);
		x++;
	}
}

void	draw_wall(t_map *map, int color, int tex_x, int tex_y)
{
	char	*dest;

	dest = map->addr + (tex_y * map->line_length + tex_x * (map->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

//void	draw_wall(t_map *map, int x)
//{
//	int		line_height;
//	int		draw_start;
//	int		draw_end;
//	int		color;
//	int		y;
//	char	*dest;

//	// le * 0.2 c'est une valeur de constante pour gerer les murs
//	line_height = (int)(SCREEN_HEIGHT / map->game->player->dda->perp_wall_dist
//			* 0.2);
//	draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
//	if (draw_start < 0)
//		draw_start = 0;
//	draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
//	if (draw_end >= SCREEN_HEIGHT)
//		draw_end = SCREEN_HEIGHT - 1;
//	color = 0x0080FF;
//	y = draw_start;
//	while (y < draw_end)
//	{
//		dest = map->addr + (y * map->line_length + x * (map->bits_per_pixel
//					/ 8));
//		*(unsigned int *)dest = color;
//		// mlx_pixel_put(map->game->mlx, map->game->mlx_win, x, y, color);
//		y++;
//	}
//}

void	draw_background(t_map *map)
{
	int		x;
	int		y;
	char	*dst;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			dst = map->addr + (y * map->line_length + x * (map->bits_per_pixel
						/ 8));
			*(unsigned int *)dst = 0x292929;
			x++;
		}
		y++;
	}
	y = SCREEN_HEIGHT / 2;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			dst = map->addr + (y * map->line_length + x * (map->bits_per_pixel
						/ 8));
			*(unsigned int *)dst = 0x303030;
			x++;
		}
		y++;
	}
}

// les deux fonctions suivantes c'est pour afficher la map en petit si on veut

// void	draw_rectangle(t_map *map, int x, int y, int size, int color)
//{
//	int i, j;
//	i = 0;
//	while (i < size)
//	{
//		j = 0;
//		while (j < size)
//		{
//			mlx_pixel_put(map->game->mlx, map->game->mlx_win, x + j, y + i,
//				color);
//			j++;
//		}
//		i++;
//	}
//}

// void	draw_background(t_map *map)
//{
//	int	rect_size;

//	rect_size = 10;
//	int i, j;
//	if (!map || !map->grid)
//	{
//		printf("Erreur : map ou grid non initialisé.\n");
//		return ;
//	}
//	i = 0;
//	while (i < map->height && map->grid[i] != (void *)0)
//	{
//		j = 0;
//		while (j < map->length && map->grid[i][j] != '\0')
//		{
//			if (map->grid[i][j] == '1')
//				draw_rectangle(map, j * rect_size, i * rect_size, rect_size,
//								0xFF0000); // Rouge
//			else if (map->grid[i][j] == '0')
//				draw_rectangle(map, j * rect_size, i * rect_size, rect_size,
//								0x0000FF); // Bleu
//			j++;
//		}
//		i++;
//	}
//}
