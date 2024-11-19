/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_strcut.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:48:18 by clmanouk          #+#    #+#             */
/*   Updated: 2024/11/19 18:53:03 by clmanouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

t_calcul_table	*ft_init_calcul(t_player *player, t_calcul_table *table)
{
	int		i;
	float	angle;
	float	relative_angle;

	while (player->angle >= 2 * M_PI)
		player->angle -= 2 * M_PI;
	while (player->angle < 0)
		player->angle += 2 * M_PI;
	i = 0;
	if (!(table->cos = malloc(sizeof(float) * TABLE_SIZE))
		|| !(table->sin = malloc(sizeof(float) * TABLE_SIZE))
		|| !(table->fish_eyes = malloc(sizeof(float) * TABLE_SIZE))
		|| !(table->tang = malloc(sizeof(float) * TABLE_SIZE)))
	{
		free(table->cos);
		free(table->sin);
		free(table->fish_eyes);
		free(table->tang);
		return (NULL);
	}
	while (i < TABLE_SIZE)
	{
		angle = (float)i * (2 * M_PI / TABLE_SIZE);
		table->sin[i] = sin(angle);
		table->cos[i] = cos(angle);
		table->tang[i] = tan(angle);
		relative_angle = angle - player->angle;
		table->fish_eyes[i] = cos(relative_angle);
		i++;
	}
	return (table);
}

void	define_fov(t_player *player)
{
	double	dir_lengh;
	double	plane_lengh;

	dir_lengh = sqrt(player->dir_x * player->dir_x + player->dir_y
			* player->dir_y);
	plane_lengh = sqrt(player->plane_x * player->plane_x + player->plane_y
			* player->plane_y);
	if (dir_lengh == 0 || plane_lengh == 0)
	{
		printf("erreur vecteur non init\n");
		player->fov = 0;
		return ;
	}
	player->fov = 2 * atan(plane_lengh / dir_lengh);
	player->fov = player->fov * RAD_TO_DEG;
}

void	define_plane(t_player *player)
{
	player->plane_x = -player->dir_y;
	player->plane_y = player->dir_x;
	define_fov(player);
}

int	ft_init_player(t_player *player, t_calcul_table *table)
{
	int	i;

	i = 0;
	player->pos_x = 22.0;
	player->pos_y = 11.5;
	player->dir_x = 1;
	player->dir_y = 0;
	player->angle = atan2(player->dir_y, player->dir_x);
	player->camera_x = malloc(sizeof(double) * SCREEN_WIDTH);
	if (!player->camera_x)
		return (FAIL);
	while (i < SCREEN_HEIGHT)
	{
		player->camera_x[i] = 2.0 * i / (double)SCREEN_WIDTH - 1;
		//printf("camera_x[%i]\n", i);
		i++;
	}
	define_plane(player);
	player->table = table;
	return (SUCCESS);
}

t_dda	*ft_init_dda(t_player *player)
{
	t_dda	*dda;
	int		i;

	i = 0;
	dda = malloc(sizeof(t_dda));
	if (!dda)
		return (NULL);
	dda->map_x = player->pos_x;
	dda->map_y = player->pos_y;
	dda->ray_dir_x = player->dir_x + player->plane_x * (*player->camera_x);
	dda->ray_dir_y = player->dir_y + player->plane_y * (*player->camera_x);
	if (dda->ray_dir_x == 0 || dda->ray_dir_y == 0)
	{
		dda->delta_dist_x = fabs(1 / 1e30);
		dda->delta_dist_y = fabs(1 / 1e30);
	}
	else
	{
		dda->delta_dist_x = fabs(1 / dda->ray_dir_x);
		dda->delta_dist_y = fabs(1 / dda->ray_dir_y);
	}
	if (dda->ray_dir_x < 0)
		dda->side_dist_x = (player->pos_x - dda->map_x) * dda->delta_dist_x;
	else
		dda->side_dist_x = (dda->map_x + 1.0 - player->pos_x)
			* dda->delta_dist_x;
	if (dda->ray_dir_y < 0)
		dda->side_dist_y = (player->pos_y - dda->map_y) * dda->delta_dist_y;
	else
		dda->side_dist_y = (dda->map_y + 1.0 - player->pos_y)
			* dda->delta_dist_y;
	dda->hit = 0;
	dda->step_x = (dda->ray_dir_x < 0) ? -1 : 1;
	dda->step_y = (dda->ray_dir_x < 0) ? -1 : 1;
	dda->perp_wall_dist = 0;
	return (dda);
}
