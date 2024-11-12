/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:26:52 by clmanouk          #+#    #+#             */
/*   Updated: 2024/11/12 16:21:58 by clmanouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Includes/cub3d.h"

char	**ft_realloc_map(t_map *map)
{
	int		i;
	char	**strs;

	i = 0;
	map->height *= 2;
	strs = ft_calloc(sizeof(char *), map->height);
	if (!strs)
		return (NULL);
	while (map->grid[i] != NULL)
	{
		strs[i] = map->grid[i];
		i++;
	}
	free(map->grid);
	return (strs);
}

int	get_map(t_map *map, const char *filename)
{
	int		i;
	int		fd;
	int		row;
	char	*line;

	i = 0;
	row = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Enter a correct name\n");
		return (0);
	}
	line = get_next_line(fd);
	if (line == NULL)
		return (ft_printf("Empty file\n"), 0);
	while (line != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (row >= map->height - 1)
			map->grid = ft_realloc_map(map);
		map->grid[row] = line;
		row++;
		line = get_next_line(fd);
	}
	return (1);
}
