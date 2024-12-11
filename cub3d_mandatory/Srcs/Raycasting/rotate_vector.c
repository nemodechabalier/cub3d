/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:57:35 by clmanouk          #+#    #+#             */
/*   Updated: 2024/12/11 12:13:53 by clmanouk         ###   ########.fr       */
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
	// pk ca ne fonction pas avec '1' ?
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

int	move_player_dir(t_map *map, t_player *player, int move_forward)
{
	double	move_speed;
	double	speed;
	double	next_pos_x;
	double	next_pos_y;

	speed = 0.1;
	move_speed = speed * (move_forward ? 1 : -1);
	next_pos_x = player->pos_x + player->dir_x * move_speed;
	next_pos_y = player->pos_y + player->dir_y * move_speed;
	// printf("Pos de x = %f\nPos de y = %f\n", player->pos_x, player->pos_y);
	// printf("Next pos de x = %f\nNext pos de y = %f\n",next_pos_x,next_pos_y);
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
}

int	move_player(int keycode, t_map *map)
{
	t_player	*player;

	player = map->game->player;
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
	else if ((keycode == 'w' || keycode == 'W') || keycode == 65362)
		move_player_dir(map, player, 1);
	else if ((keycode == 's' || keycode == 'S') || keycode == 65364)
		move_player_dir(map, player, 0);
	else if ((keycode == 'a' || keycode == 'A') || keycode == 65361)
		ft_rotate_player(player, -0.1f, player->table);
	else if ((keycode == 'd' || keycode == 'D') || keycode == 65363)
		ft_rotate_player(player, 0.1f, player->table);
	else 
		return (FAIL);
return (SUCCESS);
}
