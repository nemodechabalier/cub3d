/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_strcut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:06:17 by clmanouk          #+#    #+#             */
/*   Updated: 2024/12/13 19:06:51 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d_bonus.h"

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
		free(table);
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

void	init_player_dir_plane(t_player *player, char **file)
{
	int	i;
	int	j;

	i = 0;
	while (file[i])
	{
		j = 0;
		while (file[i][j])
		{
			if (file[i][j] == 'N')
			{
				player->dir_x = 0.0;
				player->dir_y = -1.0;
				player->plane_x = 0.66;
				player->plane_y = 0.0;
			}
			else if (file[i][j] == 'S')
			{
				player->dir_x = 0.0;
				player->dir_y = 1.0;
				player->plane_x = -0.66;
				player->plane_y = 0.0;
			}
			else if (file[i][j] == 'E')
			{
				player->dir_x = 1.0;
				player->dir_y = 0.0;
				player->plane_x = 0.0;
				player->plane_y = 0.66;
			}
			else if (file[i][j] == 'W')
			{
				player->dir_x = -1.0;
				player->dir_y = 0.0;
				player->plane_x = 0.0;
				player->plane_y = -0.66;
			}
			j++;
		}
		i++;
	}
}

void	init_position(t_player *player, char **file)
{
	int	i;
	int	j;

	i = 0;
	while (file[i])
	{
		j = 0;
		while (file[i][j])
		{
			if (file[i][j] == 'N' || file[i][j] == 'E' || file[i][j] == 'W'
				|| file[i][j] == 'S')
			{
				player->pos_x = j + 0.5;
				player->pos_y = i + 0.5;
				return ;
			}
			j++;
		}
		i++;
	}
}

t_player	*ft_init_player(t_calcul_table *table, t_player *player,
		char **file)
{
	init_position(player, file);
	init_player_dir_plane(player, file);
	printf("dir y = %f dir y = %f\n", player->dir_x, player->dir_y);
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

t_texture	*texture_constructor(t_file *file)
{
	t_texture	*text;
	int			i;

	text = malloc(sizeof(t_texture));
	if (!text)
		return (NULL);
	i = 0;
	while (file->texture[i])
	{
		if (file->texture[i][0] == 'N')
			text->path[0] = file->texture[i];
		if (file->texture[i][0] == 'S')
			text->path[1] = file->texture[i];
		if (file->texture[i][0] == 'E')
			text->path[2] = file->texture[i];
		if (file->texture[i][0] == 'W')
			text->path[3] = file->texture[i];
		i++;
	}
	return (text);
}
