/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:56:20 by clmanouk          #+#    #+#             */
/*   Updated: 2024/09/17 14:44:37 by clmanouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_file_map(char *map)
{
	int	i;

	i = ft_strlen(map);
	if (i < 5)
		return (-1);
	return (ft_strncmp(map + i - 4, ".ber", 4));
}

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac == 2 && error_file_map(av[1]) == 0)
	{
		map = start_map(100, 80);
		if (!map)
			return (ft_printf("Error initialize map\n"), 1);
		if (get_map(map, av[1]) == 0)
			return (ft_free_map(map->grid), free(map), 1);
		ft_printmap(map->grid);
		if (!(correct_map(map) == 1))
			return (ft_free_map(map->grid), free(map), 1);
		map->game.mlx = mlx_init();
		if (!map->game.mlx)
			return (ft_free_map(map->grid), free(map), 1);
		map->game.mlx_win = mlx_new_window(map->game.mlx, 32 * map->length, 32
				* map->height, "so_long :)");
		if (!map->game.mlx_win)
			return (free(map->game.mlx), ft_free_map(map->grid), free(map), 1);
		if (start_sprites(map) != 0)
			return (close_window(map), 1);
		mlx_function_call(map);
	}
	else
		ft_printf("Enter a valid map name\n");
	return (0);
}
