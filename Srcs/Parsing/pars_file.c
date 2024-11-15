/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:44:16 by nde-chab          #+#    #+#             */
/*   Updated: 2024/11/13 17:31:08 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

t_file	*take_map(char **strs, t_file *file)
{
	int	save;

	int(i) = 0;
	int(j) = 1;
	while (strs[i])
	{
		if (is_map(strs[i]))
			break ;
		i++;
	}
	if (strs[i] == NULL)
		return (t_file_dest(file), NULL);
	save = i;
	while (strs[i])
	{
		i++;
		j++;
	}
	file->map = ft_calloc(sizeof(char *), (j + 1));
	if (!file->map)
		return (t_file_dest(file), NULL);
	j = 0;
	while (strs[save])
		file->map[j++] = strs[save++];
	return (file);
}

int	pars_file(char *str)
{
	int	i;

	if (ft_empty(str))
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			if (!ft_strncmp(str + i, "NO ", 3) || !ft_strncmp(str + i, "SO ", 3)
				|| !ft_strncmp(str + i, "EA ", 3) || !ft_strncmp(str + i, "WE ",
					3))
				return (1);
			if (!ft_strncmp(str + i, "C ", 2) || !ft_strncmp(str + i, "F ", 2))
				return (2);
			else
				return (3);
		}
		i++;
	}
	return (3);
}

t_file	*take_texture(t_file *file, char **strs)
{
	int(i) = -1;
	int(j) = 0;
	int(x) = 0;
	while (strs[++i])
	{
		if (pars_file(strs[i]) == 1)
		{
			if (j > 3)
				return (printf("Error\nline: %d\n", i + 1), free(file), NULL);
			file->texture[j] = strs[i];
			j++;
		}
		else if (pars_file(strs[i]) == 2)
		{
			if (x > 1)
				return (printf("Error\nline: %d\n", i + 1), free(file), NULL);
			file->RGB[x] = strs[i];
			x++;
		}
		else if (is_map(strs[i]) && x == 2 && j == 4)
			return (file);
		else if (pars_file(strs[i]) == 3)
			return (printf("Error\nline: %d\n", i + 1), free(file), NULL);
	}
	return (file);
}

t_file	*cut_file(char **strs)
{
	t_file	*file;

	file = t_file_creator();
	if (!file)
		return (free_strs(strs), NULL);
	file = take_texture(file, strs);
	if (!file)
		return (free_strs(strs), NULL);
	file = take_map(strs, file);
	if (!file)
		return (free_strs(strs), NULL);
	return (verrif_texture(file, strs));
}
