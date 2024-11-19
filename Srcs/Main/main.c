/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:43:22 by clmanouk          #+#    #+#             */
/*   Updated: 2024/11/19 16:51:32 by clmanouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

int	main(int ac, char **av)
{
	t_map *map;
	t_file	*file;

	file = NULL;
	map = NULL;
	if (ac != 2)
		return (printf("wrong nb args\n"), -1);
	file = take_file(av[1]);
	map = start_map(file->map);
	mlx_function_call(map, file);
	return (0);
}
