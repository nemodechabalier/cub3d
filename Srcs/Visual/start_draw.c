/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:54:52 by clmanouk          #+#    #+#             */
/*   Updated: 2024/11/22 19:00:14 by clmanouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int	calculate_side(int side)
{
	if (side == 0)
		return (0);
	return (1);
}

void	draw_game(t_map *map, int side) 
{
	int	x;
	int	line;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		line = calculate_side(side);
		draw_wall(map, x, line);
		x++;
	}
}

void	draw_background(t_map *map, int side)
{
	int	half_screen;

	int(x) = 0;
	int(y) = 0;
	half_screen = SCREEN_HEIGHT / 2;
	while (x < half_screen)
	{
		while (y < SCREEN_WIDTH)
		{
			mlx_pixel_put(map->game->mlx, map->game->mlx_win, x, y, 0x87CEEB);
			y++;
		}
		x++;
	}
	y = half_screen;
	while (y < SCREEN_HEIGHT)
	{
		y = 0;
		while (y < SCREEN_HEIGHT)
		{
			mlx_pixel_put(map->game->mlx, map->game->mlx_win, x, y, 0xFF0000);
			y++;
		}
		y++;
	}
	draw_game(map, side);
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
