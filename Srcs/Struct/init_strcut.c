/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_strcut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:06:17 by clmanouk          #+#    #+#             */
/*   Updated: 2024/12/17 16:07:32 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

void	malloc_table(t_calcul_table *table)
{
	table->cos = NULL;
	table->sin = NULL;
	table->tang = NULL;
	table->cos = malloc(sizeof(float) * TABLE_SIZE);
	table->sin = malloc(sizeof(float) * TABLE_SIZE);
	table->tang = malloc(sizeof(float) * TABLE_SIZE);
}

t_calcul_table	*ft_init_calcul(t_calcul_table *table)
{
	int		i;
	float	angle;

	i = 0;
	malloc_table(table);
	if (!table->cos || !table->sin || !table->tang)
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

	text = ft_calloc(1, sizeof(t_texture));
	if (!text)
		return (NULL);
	i = 0;
	while (file->texture[i])
	{
		if (file->texture[i][0] == 'N')
			text->path[3] = file->texture[i];
		if (file->texture[i][0] == 'S')
			text->path[2] = file->texture[i];
		if (file->texture[i][0] == 'E')
			text->path[1] = file->texture[i];
		if (file->texture[i][0] == 'W')
			text->path[0] = file->texture[i];
		i++;
	}
	i = 0;
	text->img_ptr[0] = NULL;
	text->img_ptr[1] = NULL;
	text->img_ptr[2] = NULL;
	text->img_ptr[3] = NULL;
	return (text);
}
