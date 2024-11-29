/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:57:35 by clmanouk          #+#    #+#             */
/*   Updated: 2024/11/25 13:54:59 by clmanouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

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

void	ft_rotate_player(t_player *player, float rotation_angle,
		t_calcul_table *table)
{
	float	old_dir_x;
	float	old_dir_y;
	float	old_plane_x;
	float	old_plane_y;
	int		rot_index;
	float	cos_rot;
	float	sin_rot;

	if (!player || !table)
		return ;
	old_dir_x = player->dir_x;
	old_dir_y = player->dir_y;
	old_plane_x = player->plane_x;
	old_plane_y = player->plane_y;
	rot_index = get_table_index(rotation_angle);
	cos_rot = table->cos[rot_index];
	sin_rot = table->sin[rot_index];
	player->dir_x = old_dir_x * cos_rot - old_dir_y * sin_rot;
	player->dir_y = old_dir_x * sin_rot + old_dir_y * cos_rot;
	player->plane_x = old_plane_x * cos_rot - old_plane_y * sin_rot;
	player->plane_y = old_plane_x * sin_rot + old_plane_y * cos_rot;
	player->angle += rotation_angle;
	// while (player->angle >= 2 * M_PI)
	//	player->angle -= 2 * M_PI;
	// while (player->angle < 0)
	//	player->angle += 2 * M_PI;
}

int	valide_move(t_map *map, int x, int y)
{
	if (map->grid[x][y] == '1')
		return (FAIL);
	return (SUCCESS);
}

void	move_player_dir(t_map *map, t_player *player, int move_forward)
{
	double	move_speed;
	double	speed;
	double	next_pos_x;
	double	next_pos_y;

	speed = 0.05;
	move_speed = speed * (move_forward ? 1 : -1);
	next_pos_x = player->pos_x + player->dir_x * move_speed;
	next_pos_y = player->pos_y + player->dir_y * move_speed;
	if ((int)next_pos_x >= 0 && (int)next_pos_x < map->length
		&& (int)player->pos_y >= 0 && (int)player->pos_y < map->height
		&& map->grid[(int)next_pos_x][(int)player->pos_y] > 0)
	{
		player->pos_x = next_pos_x;
	}
	if ((int)player->pos_x >= 0 && (int)player->pos_x < map->length
		&& (int)next_pos_y >= 0 && (int)next_pos_y < map->height
		&& map->grid[(int)player->pos_x][(int)next_pos_y] > 0)
	{
		player->pos_y = next_pos_y;
	}
}

int	move_player(int keycode, t_map *map)
{
	if (!map->game->player->table)
		return (printf("Error: player->table is NULL\n"), FAIL);
	if (!map)
		return (printf("Map init fail\n"), FAIL);
	if (!map->game)
		return (printf("Map->game init fail\n"), FAIL);
	if (!map->game->player)
		return (printf("Map->game->player init fail\n"), FAIL);
	if (keycode == 65307)
		close_window(map);
	else if ((keycode == 'w' || keycode == 'W'))
		move_player_dir(map, map->game->player, 1);
	else if ((keycode == 's' || keycode == 'S'))
		move_player_dir(map, map->game->player, 0);
	else if ((keycode == 'a' || keycode == 'A'))
		ft_rotate_player(map->game->player, 0.1f, map->game->player->table);
	else if ((keycode == 'd' || keycode == 'D'))
		ft_rotate_player(map->game->player, -0.1f, map->game->player->table);
	else
		return (FAIL);
	return (SUCCESS);
}
