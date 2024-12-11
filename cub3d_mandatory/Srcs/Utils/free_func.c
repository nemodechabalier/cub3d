/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:50:42 by nde-chab          #+#    #+#             */
/*   Updated: 2024/12/11 17:50:05 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

void	free_strs(char **strs, int bool)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		strs[i] = NULL;
		i++;
	}
	if (bool)
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

void	close_texture(t_map *map)
{
	int			i;
	t_texture	*texture;

	i = 0;
	texture = map->game->text;
	while (i < 2)
	{
		if (texture->img_ptr[i])
			mlx_destroy_image(map->game->mlx, texture->img_ptr[i]);
		i++;
	}
	free(texture);
	// free(map->game->text);
}

void	close_image(t_map *map)
{
	if (map->img_ptr != NULL)
		mlx_destroy_image(map->game->mlx, map->img_ptr);
}

int	close_window(t_map *map)
{
	mlx_loop_end(map->game->mlx);
	close_texture(map);
	close_image(map);
	if (map->game->mlx_win)
		mlx_destroy_window(map->game->mlx, map->game->mlx_win);
	if (map->game->mlx)
	{
		mlx_destroy_display(map->game->mlx);
		free(map->game->mlx);
	}
	free(map->game->player->dda);
	free(map->game->player);
	if (map->game->table)
	{
		free(map->game->table->cos);
		free(map->game->table->sin);
		free(map->game->table->tang);
		free(map->game->table);
	}
	ft_free_map(map);
	free(map->game);
	free(map);
	exit(0);
	return (0);
}
