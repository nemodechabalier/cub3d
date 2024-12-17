/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:57:35 by clmanouk          #+#    #+#             */
/*   Updated: 2024/12/17 11:35:55 by clmanouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

int	valid_move(double x, double y, t_map *map)
{
	int	grid_x;
	int	grid_y;

	grid_x = (int)(x);
	grid_y = (int)(y);
	if (grid_x < 0 || grid_x >= map->length || grid_y < 0
		|| grid_y >= map->height)
		return (FAIL);
	if (map->grid[grid_y][grid_x] == '1')
		return (FAIL);
	return (SUCCESS);
}

int	get_table_index(float angle)
{
	int	i;

	while (angle >= 2 * M_PI)
		angle -= 2 * M_PI;
	while (angle < 0)
		angle += 2 * M_PI;
	i = (int)((angle * RAD_TO_DEG) + 0.5f) % TABLE_SIZE;
	if (i < 0)
		i += TABLE_SIZE;
	return (i);
}

int	move_player_ad(t_map *map, t_player *player, int move_dir)
{
	double	move_speed;
	double	speed;
	double	next_pos_x;
	double	next_pos_y;

	speed = 0.03;
	if (move_dir == 1)
		move_speed = speed;
	else
		move_speed = -speed;
	next_pos_x = player->pos_x + player->dir_y * move_speed;
	next_pos_y = player->pos_y - player->dir_x * move_speed;
	if (valid_move(next_pos_x, next_pos_y, map) == SUCCESS)
	{
		player->pos_x = next_pos_x;
		player->pos_y = next_pos_y;
	}
	else
		return (FAIL);
	return (SUCCESS);
}

int	move_player_dir(t_map *map, t_player *player, int move_forward)
{
	double	move_speed;
	double	speed;
	double	next_pos_x;
	double	next_pos_y;

	speed = 0.02;
	if (move_forward == 1)
		move_speed = speed * 1;
	else
		move_speed = speed * -1;
	next_pos_x = player->pos_x + player->dir_x * move_speed;
	next_pos_y = player->pos_y + player->dir_y * move_speed;
	if (valid_move(next_pos_x, next_pos_y, map) == SUCCESS)
	{
		player->pos_x = next_pos_x;
		player->pos_y = next_pos_y;
	}
	else
		return (FAIL);
	return (SUCCESS);
}

void	ft_rotate_player(t_player *player, float rotation_angle,
		t_calcul_table *table)
{
	float	old_dir_x;
	float	old_plane_x;
	int		rot_index;
	float	cos_rot;
	float	sin_rot;

	if (!player || !table)
		return ;
	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	rot_index = get_table_index(rotation_angle);
	cos_rot = table->cos[rot_index];
	sin_rot = table->sin[rot_index];
	player->dir_x = player->dir_x * cos_rot - player->dir_y * sin_rot;
	player->dir_y = old_dir_x * sin_rot + player->dir_y * cos_rot;
	player->plane_x = player->plane_x * cos_rot - player->plane_y * sin_rot;
	player->plane_y = old_plane_x * sin_rot + player->plane_y * cos_rot;
	player->angle += rotation_angle;
}
