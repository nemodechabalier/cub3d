/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:43:22 by clmanouk          #+#    #+#             */
/*   Updated: 2024/12/16 16:57:21 by clmanouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

int	main(int ac, char **av)
{
	t_map	*map;
	t_file	*file;

	file = NULL;
	map = NULL;
	if (ac != 2)
		return (printf("wrong nb args\n"), -1);
	file = take_file(av[1]);
	if (!file)
		return (0);
	map = return_value_file(file->map, file);
	init_game(map, file);
	return (0);
}
