/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:29:33 by clmanouk          #+#    #+#             */
/*   Updated: 2024/12/13 19:05:48 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d_bonus.h"

int	create_color_ceiling(t_file *file)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	if (!file)
		return (FAIL);
	r = (unsigned int)file->c[0] & 0xFF;
	g = (unsigned int)file->c[1] & 0xFF;
	b = (unsigned int)file->c[2] & 0xFF;
	return ((0xFF << 24) | (r << 16) | (g << 8) | b);
}

int	create_color_floor(t_file *file)
{
	unsigned int	t;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	if (!file)
		return (FAIL);
	t = 0xFF >> 24;
	r = (unsigned int)file->f[0] & 0xFF;
	g = (unsigned int)file->f[1] & 0xFF;
	b = (unsigned int)file->f[2] & 0xFF;
	return ((0xFF << 24) | (r << 16) | (g << 8) | b);
}

void	check_color_recup(t_file *file)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		printf("color ceiling %d\n", file->c[i]);
		printf("color floor %d\n", file->f[i]);
		i++;
	}
}
