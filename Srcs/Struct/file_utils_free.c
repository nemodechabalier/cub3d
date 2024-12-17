/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:02:09 by nde-chab          #+#    #+#             */
/*   Updated: 2024/12/16 16:57:21 by clmanouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

t_file	*t_file_creator(void)
{
	t_file	*file;

	file = malloc(sizeof(t_file));
	if (!file)
		return (NULL);
	file->map = NULL;
	file->rgb[0] = NULL;
	file->rgb[1] = NULL;
	file->rgb[2] = NULL;
	file->texture[0] = NULL;
	file->texture[1] = NULL;
	file->texture[2] = NULL;
	file->texture[3] = NULL;
	file->texture[4] = NULL;
	return (file);
}

void	file_dest(t_file *file, int i)
{
	if (file->map && i)
		free_strs(file->map, 1);
	else if (file->map)
		free(file->map);
	if (file->rgb[0])
		free(file->rgb[0]);
	if (file->rgb[1])
		free(file->rgb[1]);
	if (file->texture[0])
		free(file->texture[0]);
	if (file->texture[1])
		free(file->texture[1]);
	if (file->texture[2])
		free(file->texture[2]);
	if (file->texture[3])
		free(file->texture[3]);
	free(file);
}

void	ft_free_data(t_game *game)
{
	if (!game->table)
	{
		free(game->player);
		free(game->table);
		free(game);
	}
	if (!game->player)
	{
		free(game->table);
		free(game->player);
		free(game);
	}
}
