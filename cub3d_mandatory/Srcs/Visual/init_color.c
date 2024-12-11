/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:29:33 by clmanouk          #+#    #+#             */
/*   Updated: 2024/12/11 14:43:48 by clmanouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int	create_color_ceiling(t_file *file)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	if (!file)
		return (FAIL);
	r = (unsigned int)file->C[0] & 0xFF;
	g = (unsigned int)file->C[1] & 0xFF;
	b = (unsigned int)file->C[2] & 0xFF;
	return ((0xFF << 24) | (r << 16) | (g << 8) | b);
	//return ((r << 24) | (g << 16) | (b << 8));
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
	r = (unsigned int)file->F[0] & 0xFF;
	g = (unsigned int)file->F[1] & 0xFF;
	b = (unsigned int)file->F[2] & 0xFF;
	return ((0xFF << 24) | (r << 16) | (g << 8) | b);
	//return ((r << 24) | (g << 16) | (b << 8));
}

void	check_color_recup(t_file *file)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		// c[0] = R
		// c[1] = G
		// c[2] = B
		printf("color ceiling %d\n", file->C[i]);
		printf("color floor %d\n", file->F[i]);
		i++;
	}
}
