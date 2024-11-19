/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:47:29 by clmanouk          #+#    #+#             */
/*   Updated: 2024/11/19 18:59:33 by clmanouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

t_map	*start_map(char **file)
{
	int		i;
	int		file_height;
	t_map	*map;

	if (!file)
		return (NULL);
	file_height = 0;
	while (file[file_height] != NULL)
		file_height++;
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	memset(map, 0, sizeof(t_map));
	map->game.img.height = file_height;
	map->game.img.length = SCREEN_WIDTH;
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
		if (!map->grid[i])
		{
			while (--i >= 0)
				free(map->grid[i]);
			free(map->grid);
			free(map);
			return (NULL);
		}
		i++;
	}
	map->grid[i] = NULL;
	map->hit = 0;
	map->game.img.img_ptr = NULL;
	return (map);
}

int	mlx_init_first(t_map *map)
{
	map->game.mlx = mlx_init();
	if (!map->game.mlx)
		return (FAIL);
	map->game.mlx_win = mlx_new_window(map->game.mlx, 800, 600, "CUB3D :)");
	if (!map->game.mlx_win)
		return (FAIL);
	return (SUCCESS);
}

void	draw_rectangle(t_map *map, int x, int y, int size, int color)
{
	int i, j;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			mlx_pixel_put(map->game.mlx, map->game.mlx_win, x + j, y + i,
				color);
			j++;
		}
		i++;
	}
}

void	draw_background(t_map *map)
{
	int	rect_size;

	rect_size = 10;
	int i, j;
	if (!map || !map->grid)
	{
		printf("Erreur : map ou grid non initialisé.\n");
		return ;
	}
	i = 0;
	while (i < map->game.img.height && map->grid[i] != (void *)0)
	{
		j = 0;
		while (j < map->game.img.length && map->grid[i][j] != '\0')
		{
			if (map->grid[i][j] == '1')
				draw_rectangle(map, j * rect_size, i * rect_size, rect_size,
								0xFF0000); // Rouge
			else if (map->grid[i][j] == '2')
				draw_rectangle(map, j * rect_size, i * rect_size, rect_size,
								0x00FF00); // Vert
			else
				draw_rectangle(map, j * rect_size, i * rect_size, rect_size,
								0x0000FF); // Bleu
			j++;
		}
		i++;
	}
}

void	mlx_function_call(t_map *map, t_file *file)
{
	t_player		*player;
	t_calcul_table	*table = NULL;
	(void)file;

	player = malloc(sizeof(t_player));
	if (!player)
		return ;
	table = malloc(sizeof(t_calcul_table));
	if (!table)
		return ;
	mlx_init_first(map);
	ft_init_player(player, table);
	table = ft_init_calcul(player, table);
	ft_init_dda(player);
	mlx_loop_hook(map->game.mlx_win, &start_algo_dda, map);
	draw_background(map);
	mlx_key_hook(map->game.mlx_win, &move_player, player);
	mlx_loop(map->game.mlx);
	close_window(map);
}
