/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:57:35 by clmanouk          #+#    #+#             */
/*   Updated: 2024/12/13 17:05:03 by clmanouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int	valid_move(double x, double y, t_map *map)
{
	int	grid_x;
	int	grid_y;

	grid_x = (int)(x + 0.01);
	grid_y = (int)(y + 0.01);
	if (grid_x < 0 || grid_x >= map->length || grid_y < 0
		|| grid_y >= map->height)
		return (FAIL);
	if (map->grid[grid_y][grid_x] == '1')
	{
		if ((x - grid_x < MARGE_PLAYER && x - grid_x > 0) || (grid_x + 1
				- x < MARGE_PLAYER && grid_x + 1 - x > 0) || (y
				- grid_y < MARGE_PLAYER && y - grid_y > 0) || (grid_y + 1
				- y < MARGE_PLAYER && grid_y + 1 - y > 0))
		{
			printf("Checking position: x = %f, y = %f\n", x, y);
			printf("grid_x = %d, grid_y = %d\n", grid_x, grid_y);
			printf("map value: %c\n", map->grid[grid_y][grid_x]);
			return (FAIL);
		}
		return (FAIL);
	}
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

	speed = 0.3;
	if (move_dir == 1)
		move_speed = speed;
	else
		move_speed = -speed;
	next_pos_x = player->pos_x + player->dir_y * move_speed;
	next_pos_y = player->pos_y - player->dir_x * move_speed;
	if (valid_move(next_pos_x, player->pos_y, map) == SUCCESS)
		player->pos_x = next_pos_x;
	else
		return (FAIL);
	if (valid_move(player->pos_x, next_pos_y, map) == SUCCESS)
		player->pos_y = next_pos_y;
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

	speed = 0.3;
	if (move_forward == 1)
		move_speed = speed * 1;
	else
		move_speed = speed * -1;
	next_pos_x = player->pos_x + player->dir_x * move_speed;
	next_pos_y = player->pos_y + player->dir_y * move_speed;
	if (valid_move(next_pos_x, player->pos_y, map) == SUCCESS)
		player->pos_x = next_pos_x;
	else
		return (FAIL);
	if (valid_move(player->pos_x, next_pos_y, map) == SUCCESS)
		player->pos_y = next_pos_y;
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

void	move_rotate(t_map *map, t_player *player, float rotation_angle, t_calcul_table *table)
{
	float	old_dir_x;
	float	old_plane_x;
	int		rot_index;
	float	cos_rot;
	float	sin_rot;
	(void)map;

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
}

int	move_player(int keycode, t_map *map)
{
	t_player	*player;

	player = map->game->player;
	if (keycode == 65307)
		close_window(map);
	else if ((keycode == 'w' || keycode == 'W') || keycode == 65362)
		move_player_dir(map, player, 1);
	else if ((keycode == 's' || keycode == 'S') || keycode == 65364)
		move_player_dir(map, player, 0);
	else if (keycode == 65361)
		ft_rotate_player(player, -0.1f, player->table);
	else if (keycode == 65363)
		ft_rotate_player(player, 0.1f, player->table);
	else if ((keycode == 'a' || keycode == 'A'))
		move_player_ad(map, player, 1);
	else if ((keycode == 'd' || keycode == 'D'))
		move_player_ad(map, player, 0);
	else
		return (FAIL);
	return (SUCCESS);
}
