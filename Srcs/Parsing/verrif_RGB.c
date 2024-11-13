/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verrif_RGB.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:02:46 by nde-chab          #+#    #+#             */
/*   Updated: 2024/11/13 19:49:11 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

char	*RGB_alloc(char *str)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = ft_calloc(sizeof(char), count_alloc_texture(str) + 2);
	if (!new)
		return (NULL);
	while (i < 4 && str[i])
		new[j++] = str[i++];
	new[j++] = ' ';
	while (str[i])
	{
		if (str[i] != ' ')
			new[j++] = str[i];
		i++;
	}
	return (new);
}

int	RGB_cut(t_file *file)
{
	int	i;

	i = 0;
	while (file->RGB[i])
	{
		file->RGB[i] = RGB_alloc(file->RGB[i]);
		if (!file->RGB[i])
		{
			if (i == 1)
				free(file->RGB[0]);
			return (FALSE);
		}
		i++;
	}
	if (!strncmp(file->RGB[0], file->RGB[1], 2))
		return (printf("Error\nsame RGB\n"));
	return (TRUE);
}

//int	RGB_agrs(t_file *file)
//{
//	int	i;

//	i = 0;
//	while (file->RGB[i])
//	{
		
//	}
//}

//int	RGB_verrif(t_file *file)
//{
//	if (!RGB_cut(file))
//		return (FALSE);
//}