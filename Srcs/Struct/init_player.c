/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:58:12 by clmanouk          #+#    #+#             */
/*   Updated: 2024/12/16 17:16:03 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

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

void	init_player_dir_ew(t_player *player, char **file)
{
	int	j;

	int (i) = -1;
	while (file[++i])
	{
		j = 0;
		while (file[i][j])
		{
			if (file[i][j] == 'E')
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
	}
}

void	init_player_dir_ns(t_player *player, char **file)
{
	int	j;

	int (i) = -1;
	while (file[++i])
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
			j++;
		}
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
	init_player_dir_ns(player, file);
	init_player_dir_ew(player, file);
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
