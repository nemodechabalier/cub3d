/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_strcut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:06:17 by clmanouk          #+#    #+#             */
/*   Updated: 2024/11/23 11:54:54 by clmanouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

t_calcul_table	*ft_init_calcul(t_calcul_table *table)
{
	int		i;
	float	angle;

	i = 0;
	if (!(table->cos = malloc(sizeof(float) * TABLE_SIZE))
		|| !(table->sin = malloc(sizeof(float) * TABLE_SIZE))
		|| !(table->tang = malloc(sizeof(float) * TABLE_SIZE)))
	{
		free(table->cos);
		free(table->sin);
		free(table->tang);
		return (NULL);
	}
	while (i < TABLE_SIZE)
	{
		angle = (float)i * (2 * M_PI / TABLE_SIZE);
		table->sin[i] = sin(angle);
		table->cos[i] = cos(angle);
		table->tang[i] = tan(angle);
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

t_player	*ft_init_player(t_calcul_table *table, t_player *player)
{
	int			i;

	i = 0;
	player->pos_x = 2.5;
	player->pos_y = 2.5;
	player->dir_x = -1.0;
	player->dir_y = 0.0;
	player->angle = atan2(player->dir_y, player->dir_x);
	player->plane_x = 0.0;
	player->plane_y = 0.66;
	define_fov(player);
	player->table = table;
	player->dda = ft_init_dda();
	if (!player->dda)
	{
		printf("Error: Failed to initialize DDA\n");
		free(player);
		return (NULL);
	}
	return (player);
}

t_dda	*ft_init_dda(void)
{
	t_dda	*dda;
	int		i;

	i = 0;
	dda = malloc(sizeof(t_dda));
	if (!dda)
		return (NULL);
	dda->map_x = 0;
	dda->map_y = 0;
	dda->delta_dist_x = 0;
	dda->delta_dist_y = 0;
	dda->ray_dir_x = 0;
	dda->ray_dir_x = 0;
	dda->side_dist_x = 0;
	dda->side_dist_y = 0;
	dda->hit = 0;
	dda->step_x = 1;
	dda->step_y = 1;
	dda->perp_wall_dist = 0;
	dda->side = 0;
	return (dda);
}
