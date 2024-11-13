/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:48:14 by nde-chab          #+#    #+#             */
/*   Updated: 2024/11/13 16:10:41 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

int	file_name_ok(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 5 || ft_strncmp(".cub", str + len - 4, 5) || str[len - 5] == '/')
		return (FALSE);
	return (TRUE);
}
int	count_line(char *file_name)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n");
		return (perror(file_name), -1);
	}
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

char	**read_file(char *file_name, int nb_line)
{
	int		i;
	char	**file;
	char	*line;
	int		fd;

	i = 0;
	file = malloc(sizeof(char *) * (nb_line + 1));
	if (!file)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (i == nb_line)
			return (file[i] = NULL, free_strs(file), printf("error malloc\n"),
				NULL);
		file[i] = line;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		i++;
		line = get_next_line(fd);
	}
	file[i] = NULL;
	return (file);
}

t_file	*take_file(char *file_name)
{
	char	**strs;
	int		nb_line;

	if (!file_name_ok(file_name))
		return (printf("Error\n file name"), NULL);
	nb_line = count_line(file_name);
	if (nb_line < 9)
	{
		if (nb_line != -1)
			printf("Error\nfile can't be correct need more line");
		return (NULL);
	}
	strs = read_file(file_name, nb_line);
	if (!strs)
		return (printf("strs == NULL\n"), NULL);
	else
		return(cut_file(strs));
}
