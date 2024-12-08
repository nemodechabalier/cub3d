/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_raycast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:18:29 by clmanouk          #+#    #+#             */
/*   Updated: 2024/12/05 20:58:35 by clmanouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int	init_game(t_map *map)
{
	t_texture	*texture;

	texture = malloc(sizeof(t_texture) * 2);
	if (!texture)
		return FAIL;
	map->game->text = ft_init_texture(map->game, texture);
	if (!map->game->text)
		return FAIL;
	mlx_loop_hook(map->game->mlx, &render, map);
	mlx_hook(map->game->mlx_win, 2, 1, &move_player, map);
	mlx_hook(map->game->mlx_win, 17, 0, close_window, map);
	mlx_loop(map->game->mlx);
	close_window(map);
	return (SUCCESS);
}

// mlx_mouse_hook ( void *win_ptr, int (*funct_ptr)(), void *param );