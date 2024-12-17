/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:42:49 by clmanouk          #+#    #+#             */
/*   Updated: 2024/12/16 17:43:33 by clmanouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

int	move_player(int keycode, t_map *map)
{
	if (keycode == 65307)
		close_window(map);
	else if (keycode == 'w' || keycode == 'W' || (keycode == 65362))
		map->game->keys[key_w] = true;
	else if (keycode == 's' || keycode == 'S' || keycode == 65364)
		map->game->keys[key_s] = true;
	else if (keycode == 65361)
		map->game->keys[key_left] = true;
	else if (keycode == 65363)
		map->game->keys[key_right] = true;
	else if ((keycode == 'a' || keycode == 'A'))
		map->game->keys[key_a] = true;
	else if ((keycode == 'd' || keycode == 'D'))
		map->game->keys[key_d] = true;
	else
		return (FAIL);
	return (SUCCESS);
}
