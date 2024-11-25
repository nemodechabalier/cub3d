/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:50:42 by nde-chab          #+#    #+#             */
/*   Updated: 2024/11/25 12:00:52 by clmanouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		strs[i] = NULL;
		i++;
	}
	free(strs);
	strs = NULL;
}

void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map && map->grid)
	{
		while (i < map->height)
		{
			if (map->grid[i])
			{
				free(map->grid[i]);
				map->grid[i] = NULL;
			}
			i++;
		}
	}
	free(map->grid);
	map->grid = NULL;
}

void	close_image(t_map *map)
{
	if (map->img_ptr != NULL)
		mlx_destroy_image(map->game->mlx, map->img_ptr);
}

int	close_window(t_map *map)
{
	mlx_loop_end(map->game->mlx);
	mlx_destroy_window(map->game->mlx, map->game->mlx_win);
	close_image(map);
	mlx_destroy_display(map->game->mlx);
	free(map->game->mlx);
	free(map->game->player);
	free(map->game->table);
	ft_free_map(map);
	free(map->game);
	free(map);
	exit(0);
	return (0);
}
