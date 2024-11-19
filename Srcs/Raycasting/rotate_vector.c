/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:57:35 by clmanouk          #+#    #+#             */
/*   Updated: 2024/11/19 18:20:02 by clmanouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int	get_table_index(float angle)
{
	int	i;

	// Normaliser l'angle entre 0 et 2π
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

	(void)table;
	old_dir_x = player->dir_x;
	old_dir_y = player->dir_y;
	old_plane_x = player->plane_x;
	old_plane_y = player->plane_y;
	//printf("Angle en radians : %f\n", rotation_angle);
	rot_index = get_table_index(rotation_angle);
	if (!table || !table->cos || !table->sin)
	{
		fprintf(stderr, "Error: table not initialized properly\n");
		return ;
	}
	cos_rot = table->cos[rot_index];
	sin_rot = table->sin[rot_index];
	printf("%f\n%f\n", cos_rot, sin_rot);
	player->dir_x = old_dir_x * cos_rot - old_dir_y * sin_rot;
	player->dir_y = old_dir_x * sin_rot + old_dir_y * cos_rot;
	player->plane_x = old_plane_x * cos_rot - old_plane_y * sin_rot;
	player->plane_y = old_plane_y * sin_rot + old_plane_y * cos_rot;
	player->angle += rotation_angle;
	while (player->angle >= 2 * M_PI)
		player->angle -= 2 * M_PI;
	while (player->angle < 0)
		player->angle += 2 * M_PI;
}

int	move_player(int keycode, t_player *player)
{
	//(void)map;
	//(void)table;
	//if (keycode == 65307)
	//	close_window(map);
	// else if ((keycode == 'w' || keycode == 'W') && valid_move(map))
	//	ft_rotate_player(player, 0.1f, table); //  a redefinir correctement
	// else if ((keycode == 's' || keycode == 'S') && valid_move(map))
	//	ft_rotate_player(player, 0.1f, table); // a redefinir correctement
	if ((keycode == 'a' || keycode == 'A'))
		ft_rotate_player(player, -0.1f, player->table);
	else if ((keycode == 'd' || keycode == 'D'))
		ft_rotate_player(player, 0.1f, player->table);
	else
		return (FAIL);
	return (SUCCESS);
}
