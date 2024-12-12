/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:54:52 by clmanouk          #+#    #+#             */
/*   Updated: 2024/12/12 14:40:48 by clmanouk         ###   ########.fr       */
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

