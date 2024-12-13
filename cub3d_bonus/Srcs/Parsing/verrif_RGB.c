/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verrif_RGB.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:02:46 by nde-chab          #+#    #+#             */
/*   Updated: 2024/12/13 19:01:26 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d_bonus.h"

char	*rgb_cut(char *str)
{
	char	*new;

	int (i) = 0;
	int (nb) = 0;
	new = ft_calloc(sizeof(char), ft_strlen(str) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (str[i] == ' ')
		i++;
	nb = 0;
	new[nb++] = str[i++];
	new[nb++] = ' ';
	while (str[i])
	{
		if (str[i] != ' ')
			new[nb++] = str[i];
		i++;
	}
	return (new);
}

int	ft_atorgb(const char *str)
{
	int	i;
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]) == 1)
	{
		result = result * 10 + (str[i++] - '0');
		if (result >= 256)
			return (256);
	}
	return (result * sign);
}

int	rgb_parse(char *rgb)
{
	int	i;

	i = 2;
	if (!ft_isdigit(rgb[i]))
		return (FALSE);
	while (ft_isdigit(rgb[i]))
		i++;
	if (rgb[i] != ',')
		return (FALSE);
	i++;
	if (!ft_isdigit(rgb[i]))
		return (FALSE);
	while (ft_isdigit(rgb[i]))
		i++;
	if (rgb[i] != ',')
		return (FALSE);
	i++;
	if (!ft_isdigit(rgb[i]))
		return (FALSE);
	while (ft_isdigit(rgb[i]))
		i++;
	if (rgb[i])
		return (FALSE);
	return (TRUE);
}

int	rgb_take(int *FC, char *rgb)
{
	int	i;

	i = 0;
	while (!ft_isdigit(rgb[i]) && rgb[i])
		i++;
	FC[0] = ft_atorgb(rgb + i);
	while (rgb[i] != ',' && rgb[i])
		i++;
	i++;
	FC[1] = ft_atorgb(rgb + i);
	while (rgb[i] != ',' && rgb[i])
		i++;
	i++;
	FC[2] = ft_atorgb(rgb + i);
	i = 0;
	while (i < 3)
	{
		if (FC[i] > 255)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_file	*rgb_verrif(t_file *file, char **strs)
{
	char	*temp;

	file->rgb[0] = rgb_cut(file->rgb[0]);
	if (!file->rgb[0])
		return (free_strs(file->texture, 0), free(file), free_strs(strs, 1),
			NULL);
	file->rgb[1] = rgb_cut(file->rgb[1]);
	if (!file->rgb[1])
		return (free_strs(file->texture, 0), free(file->rgb[0]), free(file),
			free_strs(strs, 1), NULL);
	if (!ft_strncmp(file->rgb[0], file->rgb[1], 2)
		|| rgb_parse(file->rgb[0]) == FALSE || rgb_parse(file->rgb[1]) == FALSE)
		return (printf("Error\nrgb\n"), file_dest(file, 0), free_strs(strs, 1),
			NULL);
	if (file->rgb[0][0] == 'C')
	{
		temp = file->rgb[0];
		file->rgb[0] = file->rgb[1];
		file->rgb[1] = temp;
	}
	if (rgb_take(file->f, file->rgb[0]) == FALSE || rgb_take(file->c,
			file->rgb[1]) == FALSE)
		return (printf("Error\nrgb value\n"), file_dest(file, 0),
			free_strs(strs, 1), NULL);
	return (free_file(strs), file);
}
