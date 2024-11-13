/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:02:09 by nde-chab          #+#    #+#             */
/*   Updated: 2024/11/13 15:49:41 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

t_file	*t_file_creator(void)
{
	t_file	*file;

	file = malloc(sizeof(t_file));
	if (!file)
		return (NULL);
	file->map = NULL;
	file->RGB[0] = NULL;
	file->RGB[1] = NULL;
	file->RGB[2] = NULL;
	file->texture[0] = NULL;
	file->texture[1] = NULL;
	file->texture[2] = NULL;
	file->texture[3] = NULL;
	file->texture[4] = NULL;
	return (file);
}

void	t_file_dest(t_file *file)
{
	if (file->map)
		free_strs(file->map);
	if (file->RGB[0])
		free(file->RGB[0]);
	if (file->RGB[1])
		free(file->RGB[1]);
	if (file->texture[0])
		free(file->texture[0]);
	if (file->texture[1])
		free(file->texture[1]);
	if (file->texture[2])
		free(file->texture[2]);
	if (file->texture[3])
		free(file->texture[3]);
}