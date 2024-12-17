/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:52:15 by nde-chab          #+#    #+#             */
/*   Updated: 2024/10/07 17:37:11 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	reinit_save(char *str)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		str[i++] = '\0';
	}
}

char	*ft_creat_save(char *line, char *save)
{
	int	i;
	int	lenth;

	i = 0;
	lenth = ft_strlen(line);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	if (i < lenth)
	{
		ft_strncpy(save, line + i, lenth - i);
		return (save);
	}
	else
		return (NULL);
}

char	*ft_creat_line(char *save)
{
	int		i;
	char	*line;

	line = NULL;
	i = 0;
	if (save[0] == 0)
		return (free(save), NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	line = ft_str_calloc(i + 1);
	if (!line)
		return (free(save), NULL);
	line = ft_strncpy(line, save, i);
	return (free(save), line);
}

char	*ft_creat_buffer(int fd, char *save)
{
	char	*buffer;
	int		nb_bytes;

	nb_bytes = 1;
	buffer = ft_str_calloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(save), NULL);
	while (ft_str_return(save) == 0 && nb_bytes > 0)
	{
		nb_bytes = read(fd, buffer, BUFFER_SIZE);
		if (nb_bytes > 0)
		{
			buffer[nb_bytes] = 0;
			save = ft_strjoin_free(save, buffer);
			if (!save)
				return (free(buffer), NULL);
		}
	}
	return (free(buffer), save);
}

char	*get_next_line(int fd)
{
	static char	save[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) != 0)
		return (reinit_save(save), NULL);
	line = ft_str_calloc(BUFFER_SIZE + 1);
	if (!line)
		return (reinit_save(save), NULL);
	line = ft_strncpy(line, save, BUFFER_SIZE + 1);
	ft_bzero(save, BUFFER_SIZE + 1);
	line = ft_creat_buffer(fd, line);
	if (!line)
		return (reinit_save(save), NULL);
	ft_creat_save(line, save);
	line = ft_creat_line(line);
	if (!line)
		return (reinit_save(save), NULL);
	return (line);
}
