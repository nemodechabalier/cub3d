/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verrif_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:57:00 by nde-chab          #+#    #+#             */
/*   Updated: 2025/01/15 18:54:02 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

int	verrif_start_wall(char **map, int i, int j, int len)
{
	if (map[i][j] != '1' || j == 0 || (ft_strchr("01NSEW", map[i][j - 1])))
		return (0);
	if (i == 0)
	{
		if ((int)ft_strlen(map[i + 1]) <= j
			|| !ft_strchr("0NSEW", map[i + 1][j]))
			return (0);
		return (1);
	}
	if (i == len - 1)
	{
		if ((int)ft_strlen(map[i - 1]) <= j
			|| !ft_strchr("0NSEW", map[i - 1][j]))
			return (0);
		return (1);
	}
	else if (((int)ft_strlen(map[i - 1]) <= j
			|| !ft_strchr("0NSEW", map[i - 1][j]))
			&& ((int)ft_strlen(map[i + 1]) <= j
			|| !ft_strchr("0NSEW", map[i + 1][j])))
		return (0);
	return (1);
}

int	verrif_end_wall(char **map, int i, int j, int len)
{
	if (map[i][j] != '1' || (ft_strchr("01NSEW", map[i][j + 1]) && map[i][j
			+ 1] != '\0'))
		return (0);
	if (i == 0)
	{
		if ((int)ft_strlen(map[i + 1]) <= j
			|| !ft_strchr("0NSEW", map[i + 1][j]))
			return (0);
		return (1);
	}
	if (i == len - 1)
	{
		if ((int)ft_strlen(map[i - 1]) <= j
			|| !ft_strchr("0NSEW", map[i - 1][j]))
			return (0);
		return (1);
	}
	else if (((int)ft_strlen(map[i - 1]) <= j
			|| !ft_strchr("0NSEW", map[i - 1][j]))
			&& ((int)ft_strlen(map[i + 1]) <= j
			|| !ft_strchr("0NSEW", map[i + 1][j])))
		return (0);
	return (1);
}

int	add_wall(t_file *file)
{
	int		i;
	int		len;
	char	*new;
	int		j;

	i = 0;
	len = 0;
	while (file->map[len])
		len++;
	while (file->map[i])
	{
		j = 0;
		while (file->map[i][j])
		{
			if (verrif_start_wall(file->map, i, j, len))
				file->map[i][j - 1] = '1';
			if (verrif_end_wall(file->map, i, j, len))
			{
				if (file->map[i][j + 1] != '\0')
					file->map[i][j + 1] = '1';
				else
				{
					new = ft_strjoin(file->map[i], "1");
					if (!new)
						return (FAIL);
					free(file->map[i]);
					file->map[i] = new;
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

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
