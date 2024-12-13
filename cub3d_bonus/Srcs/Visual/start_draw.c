/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:54:52 by clmanouk          #+#    #+#             */
/*   Updated: 2024/12/13 17:45:40 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d_bonus.h"

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
				*(unsigned int *)dst = map->color[0];
			}
			else
			{
				*(unsigned int *)dst = map->color[1];
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
			else if (ft_strchr("NSWE", map->grid[y][x]))
				color = 0xeb3437;
			if(map->grid[y][x] == '\0')
				break ;
			if (ft_strchr("NSWE01", map->grid[y][x]))
				draw_rectangle(map, mini_screen_x, mini_screen_y, color,
					mini_size);
			x++;
		}
		y++;
	}
}
