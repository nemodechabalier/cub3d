/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:59:14 by clmanouk          #+#    #+#             */
/*   Updated: 2024/11/23 12:44:52 by clmanouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

t_map	*return_value_file(char **file)
{
	int		file_height;
	int		file_length;
	t_map	*map;

	int(i) = 0;
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	if (!file)
		return (NULL);
	file_height = 0;
	while (file[file_height] != NULL)
		file_height++;
	file_length = 0;
	while (i < file_height)
	{
		map->line_length = ft_strlen(file[i]);
		if (map->line_length > file_length)
			file_length = map->line_length;
		i++;
	}
	if (!copy_map(map, file, file_height, file_height))
		return (NULL);
	return (map);
}

t_map	*copy_map(t_map *map, char **file, int file_height, int file_length)
{
	int	i;

	if (!file)
		return (NULL);
	ft_memset(map, 0, sizeof(t_map));
	map->grid = malloc(sizeof(char *) * (file_height + 1));
	if (!map->grid)
	{
		free(map);
		return (NULL);
	}
	i = 0;
	while (i < file_height && file[i] != NULL)
	{
		map->grid[i] = ft_strdup(file[i]);
		i++;
	}
	map->img_ptr = NULL;
	map->height = file_height;
	map->length = file_length;
	map->addr = NULL;
	map->bits_per_pixel = 0;
	map->endian = 0;
	map->game = ft_init_game_data();
	return (map);
}

t_game	*ft_init_game_data(void)
{
	t_game			*game;
	t_player		*player;
	t_calcul_table	*table;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	table = malloc(sizeof(t_calcul_table));
	if (!table)
		return (NULL);
	game->table = ft_init_calcul(table);
	if (!game->table)
	{
		ft_free_data(game);
		return (NULL);
	}
	game->player = ft_init_player(table, player);
	if (!game->player)
	{
		ft_free_data(game);
		return (NULL);
	}
	return (game);
}
