/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:46:11 by clmanouk          #+#    #+#             */
/*   Updated: 2024/12/10 18:40:24 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

//(Digital Differential Analyzer)

/*
fabs return absolute value
*/
void	calcul_ray_dir(t_player *player, int x)
{
	float	camera_x;

	camera_x = 2 * x / (float)SCREEN_WIDTH - 1;
	player->dda->ray_dir_x = player->dir_x + player->plane_x * camera_x;
	player->dda->ray_dir_y = player->dir_y + player->plane_y * camera_x;
	if (player->dda->ray_dir_x == 0)
		player->dda->delta_dist_x = 1e30;
	else
		player->dda->delta_dist_x = fabs(1 / player->dda->ray_dir_x);
	if (player->dda->ray_dir_y == 0)
		player->dda->delta_dist_y = 1e30;
	else
		player->dda->delta_dist_y = fabs(1 / player->dda->ray_dir_y);
}

void	init_pos_map(t_player *player)
{
	player->dda->map_x = (int)player->pos_x;
	player->dda->map_y = (int)player->pos_y;
}

void	init_dda(t_player *player)
{
	init_pos_map(player);
	if (player->dda->ray_dir_x < 0)
	{
		player->dda->step_x = -1;
		player->dda->side_dist_x = (player->pos_x - player->dda->map_x)
			* player->dda->delta_dist_x;
	}
	else
	{
		player->dda->step_x = 1;
		player->dda->side_dist_x = (player->dda->map_x + 1.0 - player->pos_x)
			* player->dda->delta_dist_x;
	}
	if (player->dda->ray_dir_y < 0)
	{
		player->dda->step_y = -1;
		player->dda->side_dist_y = (player->pos_y - player->dda->map_y)
			* player->dda->delta_dist_y;
	}
	else
	{
		player->dda->step_y = 1;
		player->dda->side_dist_y = (player->dda->map_y + 1.0 - player->pos_y)
			* player->dda->delta_dist_y;
	}
}

// void	continue_algo(t_player *player)
//{
//	if (player->dda->side_dist_x < player->dda->side_dist_y)
//	{
//		player->dda->side_dist_x += player->dda->delta_dist_x;
//		player->dda->map_x += player->dda->step_x;
//		player->dda->side = 0;
//	}
//	else
//	{
//		player->dda->side_dist_y += player->dda->delta_dist_y;
//		player->dda->map_y += player->dda->step_y;
//		player->dda->side = 1;
//	}
//}

void	chose_dist(t_player *player)
{
	if (player->dda->side == 0)
		player->dda->perp_wall_dist = (player->dda->side_dist_x
				- player->dda->delta_dist_x);
	else
		player->dda->perp_wall_dist = (player->dda->side_dist_y
				- player->dda->delta_dist_y);
}

int	start_algo_dda(t_map *map, t_player *player, int x)
{
	calcul_ray_dir(player, x);
	init_dda(player);
	player->dda->hit = 0;
	while (player->dda->hit == 0)
	{
		if (player->dda->side_dist_x < player->dda->side_dist_y)
		{
			player->dda->side_dist_x += player->dda->delta_dist_x;
			player->dda->map_x += player->dda->step_x;
			player->dda->side = 0;
		}
		else
		{
			player->dda->side_dist_y += player->dda->delta_dist_y;
			player->dda->map_y += player->dda->step_y;
			player->dda->side = 1;
		}
		if (player->dda->map_x < 0 || player->dda->map_x >= map->length
			|| player->dda->map_y < 0 || player->dda->map_y >= map->height)
			//return (printf("Error limit map\n"), 1);
			return (1);
		if (map->grid[player->dda->map_y][player->dda->map_x] == '1')
		{
			player->dda->hit = 1;
			break ;
		}
	}
	chose_dist(player);
	return (0);
}
