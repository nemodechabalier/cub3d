/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verrif_RGB.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:02:46 by nde-chab          #+#    #+#             */
/*   Updated: 2024/12/11 18:32:38 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

char	*RGB_cut(char *str)
{
	int		i;
	int		nb;
	char	*new;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			nb++;
		i++;
	}
	new = ft_calloc(sizeof(char), (nb + 2));
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

t_file	*RGB_verrif(t_file *file, char **strs)
{
	(void)strs;
	char *temp;
	file->RGB[0] = RGB_cut(file->RGB[0]);
	if (!file->RGB[0])
		return (free_strs(file->texture, 1), free(file), NULL);
	file->RGB[1] = RGB_cut(file->RGB[1]);
	if (!file->RGB[1])
		return (free_strs(file->texture, 0), free(file->RGB[0]), free(file),
			NULL);
	if (!ft_strncmp(file->RGB[0], file->RGB[1], 2)
		|| RGB_parse(file->RGB[0]) == FALSE || RGB_parse(file->RGB[1]) == FALSE)
		return (printf("Error\nRGB\n"), file_dest(file), NULL);
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