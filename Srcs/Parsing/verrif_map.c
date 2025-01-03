/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verrif_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:57:00 by nde-chab          #+#    #+#             */
/*   Updated: 2024/12/17 16:21:03 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

int	map_double(t_file *file)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	nb = 0;
	while (file->map[i])
	{
		j = 0;
		while (file->map[i][j])
		{
			if (!ft_strchr("N SEW01", file->map[i][j]))
				return (printf("Error\nmaps forbiden char\n"), 1);
			if (ft_strchr("NSEW", file->map[i][j]))
				nb++;
			j++;
		}
		i++;
	}
	if (nb > 1)
		return (printf("Error\ntoo many player\n"), 1);
	if (nb < 1)
		return (printf("Error\nno player\n"), 1);
	return (0);
}

int	map_char(char **map, int i, int j)
{
	int	size;

	size = 0;
	while (map[size])
		size++;
	if (i == 0 || i == size - 1 || j == 0 || j == (int)ft_strlen(map[i]) - 1
		|| j >= (int)ft_strlen(map[i - 1]) || j >= (int)ft_strlen(map[i + 1]))
		return (ft_printf("Error\nmap incorrect\n"), 1);
	if (map[i + 1][j] == ' ' || map[i - 1][j] == ' ' || map[i][j + 1] == ' '
		|| map[i][j - 1] == ' ')
		return (ft_printf("Error\nmap incorrect\n"), 1);
	return (0);
}

int	map_verrif(t_file *file)
{
	int	i;
	int	j;

	if (map_double(file))
		return (1);
	i = 0;
	while (file->map[i])
	{
		j = 0;
		while (file->map[i][j])
		{
			if (ft_strchr("0WSEN", file->map[i][j]) && map_char(file->map, i,
					j))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
