/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_raycast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:18:29 by clmanouk          #+#    #+#             */
/*   Updated: 2024/11/22 17:39:37 by clmanouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int	init_game(t_map *map)
{
	map->game->mlx = mlx_init();
	if (!map->game->mlx)
		return (printf("ERREUR init mlx\n"), 1);
	map->game->mlx_win = mlx_new_window(map->game->mlx, SCREEN_WIDTH,
			SCREEN_HEIGHT, "CUB3D");
	if (!map->game->mlx_win)
		return (printf("ERREUR init mlx\n"), 1);
	mlx_loop_hook(map->game->mlx, &render, map);
	mlx_key_hook(map->game->mlx_win, &move_player, map->game->player);
	mlx_loop(map->game->mlx);
	close_window(map);
	return (0);
}
