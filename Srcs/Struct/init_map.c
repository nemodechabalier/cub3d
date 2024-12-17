/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:59:14 by clmanouk          #+#    #+#             */
/*   Updated: 2024/12/16 18:02:20 by clmanouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

int	return_len(int nb)
{
	static int	len = 0;

	if (nb != -1)
		len = nb;
	return (len);
}

t_map	*return_value_file(char **file, t_file *files)
{
	int		file_height;
	int		file_length;
	t_map	*map;

	int (i) = 0;
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
	return_len(file_length);
	if (!copy_map(map, file, file_height, files))
		return (free(map), NULL);
	return (map);
}

t_map	*copy_map(t_map *map, char **file, int file_height, t_file *files)
{
	int	i;

	if (!file)
		return (NULL);
	map->grid = malloc(sizeof(char *) * (file_height));
	if (!map->grid)
		return (free(map->grid), free(map), NULL);
	i = 0;
	while (i < file_height && file[i] != NULL)
	{
		map->grid[i] = ft_strdup(file[i]);
		i++;
	}
	map->img_ptr = NULL;
	map->height = file_height;
	map->length = return_len(-1);
	map->color[0] = create_color_ceiling(files);
	map->color[1] = create_color_floor(files);
	map->game = ft_init_game_data(file);
	if (!map->game)
		return (free(map->game), free(map), NULL);
	return (map);
}

t_game	*ft_init_game_data(char **file)
{
	t_game			*game;
	t_player		*player;
	t_calcul_table	*table;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	player = ft_calloc(1, sizeof(t_player));
	if (!player)
		return (NULL);
	table = malloc(sizeof(t_calcul_table));
	if (!table)
		return (NULL);
	game->table = ft_init_calcul(table);
	if (!game->table)
		return (ft_free_data(game), NULL);
	game->player = ft_init_player(table, player, file);
	if (!game->player)
		return (ft_free_data(game), NULL);
	return (game);
}
