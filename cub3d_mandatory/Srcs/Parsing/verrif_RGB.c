/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verrif_RGB.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:02:46 by nde-chab          #+#    #+#             */
/*   Updated: 2024/12/11 14:49:44 by clmanouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

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

int	RGB_parse(char *RGB)
{
	int	i;

	i = 2;
	if (!ft_isdigit(RGB[i]))
		return (FALSE);
	while (ft_isdigit(RGB[i]))
		i++;
	if (RGB[i] != ',')
		return (FALSE);
	i++;
	if (!ft_isdigit(RGB[i]))
		return (FALSE);
	while (ft_isdigit(RGB[i]))
		i++;
	if (RGB[i] != ',')
		return (FALSE);
	i++;
	if (!ft_isdigit(RGB[i]))
		return (FALSE);
	while (ft_isdigit(RGB[i]))
		i++;
	if (RGB[i])
		return (FALSE);
	return (TRUE);
}

int	RGB_take(int *FC, char *RGB)
{
	int	i;

	i = 0;
	while (!ft_isdigit(RGB[i]) && RGB[i])
		i++;
	FC[0] = ft_atorgb(RGB + i);
	while (RGB[i] != ',' && RGB[i])
		i++;
	i++;
	FC[1] = ft_atorgb(RGB + i);
	while (RGB[i] != ',' && RGB[i])
		i++;
	i++;
	FC[2] = ft_atorgb(RGB + i);
	i = 0;
	while (i < 3)
	{
		if (FC[i] > 255)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_file	*RGB_verrif(t_file *file)
{
	char *temp;
	if (!ft_strncmp(file->RGB[0], file->RGB[1], 2)
		|| RGB_parse(file->RGB[0]) == FALSE || RGB_parse(file->RGB[1]) == FALSE)
		return (printf("Error\nRGB\n"),  file_dest(file), NULL);
	if (file->RGB[0][0] == 'C')
	{
		temp = file->RGB[0];
		file->RGB[0] = file->RGB[1];
		file->RGB[1] = temp;
	}
	if (RGB_take(file->F, file->RGB[0]) == FALSE || RGB_take(file->C,
			file->RGB[1]) == FALSE)
		return (printf("Error\nRGB value\n"), file_dest(file), NULL);
	return (file);
}