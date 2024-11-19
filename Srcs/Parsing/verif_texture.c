/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:57:33 by nde-chab          #+#    #+#             */
/*   Updated: 2024/11/19 16:24:27 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

int	double_texture(t_file *file)
{
	int	i;
	int	j;

	i = 0;
	while (file->texture[i])
	{
		j = i + 1;
		while (file->texture[j])
		{
			if (!ft_strncmp(file->texture[i], file->texture[j], 3))
			{
				free(file->texture[0]);
				free(file->texture[1]);
				free(file->texture[2]);
				free(file->texture[3]);
				return (FALSE);
			}
			j++;
		}
		i++;
	}
	return (TRUE);
}

char	*alloc_texture(char *str)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (count_word(str, ' ') != 2)
		return (printf("Error\ntexture\n"), NULL);
	new = malloc(sizeof(char) * (count_alloc_texture(str) + 2));
	if (!new)
		return (NULL);
	while (str[i] == ' ')
		i++;
	while (str[i] != ' ' && str[i])
		new[j++] = str[i++];
	new[j++] = ' ';
	while (str[i] == ' ')
		i++;
	while (str[i] != ' ' && str[i])
		new[j++] = str[i++];
	new[j] = '\0';
	return (new);
}

int	cut_texture(t_file *file)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (file->texture[i])
	{
		file->texture[i] = alloc_texture(file->texture[i]);
		if (!file->texture[i])
		{
			while (j < i)
				free(file->texture[j++]);
			return (FALSE);
		}
		i++;
	}
	return (1);
}

t_file	*verrif_texture(t_file *file, char **strs)
{
	if (cut_texture(file) == FALSE)
		return (free(file->map), free(file), free_strs(strs), NULL);
	if (double_texture(file) == FALSE || map_verrif(file))
		return (free(file->map), free(file), free_strs(strs), NULL);
	return (NULL);
}