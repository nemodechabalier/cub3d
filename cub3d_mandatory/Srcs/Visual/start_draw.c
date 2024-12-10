/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:54:52 by clmanouk          #+#    #+#             */
/*   Updated: 2024/12/10 19:28:34 by clmanouk         ###   ########.fr       */
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
		get_texture_position(map, map->game->player, x);
		x++;
	}
}

/*
calculate the memory offset using the line length set by mlx_get_data_addr.
We can calculate it very easily by using the following formula
int		offset = (y * line_length + x * (bits_per_pixel / 8));
*/
void	draw_wall(t_map *map, int *color, int tex_x, int tex_y)
{
	char	*dest;

	dest = map->addr + (tex_y * map->line_length + tex_x * (map->bits_per_pixel
				/ 8));
	*(unsigned int *)dest = *color;
}

void	draw_background(t_map *map)
{
	char	*dst;

	// int		rect_x;
	// int		rect_y;
	int(x) = 0;
	int(y) = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			dst = map->addr + (y * map->line_length + x * (map->bits_per_pixel
						/ 8));
			if (y < SCREEN_HEIGHT / 2)
			{
				// rect_x = x / RECTANGLE_WIDTH;
				// rect_y = y / RECTANGLE_HEIGHT;
				// if (rect_x + rect_y % 2 == 0)
				//	*(unsigned int *)dst = CEILING_COLOR1;
				// else
				*(unsigned int *)dst = CEILING_COLOR2;
			}
			else
			{
				*(unsigned int *)dst = FLOOR_COLOR;
			}
			x++;
		}
		y++;
	}
}

void	draw_rectangle(t_map *map, int mini_screen_x, int mini_screen_y,
		unsigned int color, int mini_size)
{
	char	*dst;
	float	mini_y;
	float	mini_x;

	mini_y = mini_screen_y;
	while (mini_y < mini_screen_y + mini_size)
	{
		mini_x = mini_screen_x;
		while (mini_x < mini_screen_x + mini_size)
		{
			dst = map->addr + (int)(mini_y * map->line_length + mini_x
					* (map->bits_per_pixel / 8));
			*(unsigned int *)dst = color;
			mini_x++;
		}
		mini_y++;
	}
}

void	draw_minimap(t_map *map, int minimap_size)
{
	float			mini_size;
	int				mini_screen_x;
	int				mini_screen_y;
	unsigned int	color;
	int				x;
	int				y;

	mini_size = minimap_size / (float)map->length;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->length)
		{
			mini_screen_x = x * mini_size;
			mini_screen_y = y * mini_size;
			if (map->grid[y][x] == '1')
				color = 0x505050;
			else if (map->grid[y][x] == '0')
				color = 0x202020;
			else if (map->grid[y][x] == ' ')
				color = 0x000000;
			else
				break ;
			draw_rectangle(map, mini_screen_x, mini_screen_y, color, mini_size);
			x++;
		}
		y++;
	}
}
