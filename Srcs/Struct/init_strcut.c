/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_strcut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:11:00 by clmanouk          #+#    #+#             */
/*   Updated: 2024/11/12 14:32:13 by clmanouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	init_data(void)
{
	t_data *data;
	
	data = malloc(sizeof(t_data));
	if (!data)
		return ;
	data->height = 0;
	data->length = 0;
}

t_calcul_table	init_calcul(int width_window, float fov)
{
	t_calcul_table *table;
	
	table = malloc(sizeof(t_calcul_table));
	if (!table)
		return ;
	table->cos = malloc(sizeof(float) * TABLE_SIZE);
	if (!table->cos)
		return ;
	table->sin = malloc(sizeof(float) * TABLE_SIZE);
	if (!table->cos)
		return ;
	table->fish_eyes = malloc(sizeof(float) * TABLE_SIZE);
	if (!table->fish_eyes)
		return ;
	table->tang = malloc(sizeof(float) * TABLE_SIZE);
	if (!table->tang)
		return ;
	table->calcul_angle_fov = malloc(sizeof(float) * width_window);
	if (!table->calcul_angle_fov)
		return ;
}
