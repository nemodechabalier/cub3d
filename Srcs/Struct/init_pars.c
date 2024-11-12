/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:02:09 by nde-chab          #+#    #+#             */
/*   Updated: 2024/11/12 19:45:36 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Includes/cub3d.h"

t_file *create_file(void)
{
	t_file *file;
	file = malloc (sizeof(t_file));
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