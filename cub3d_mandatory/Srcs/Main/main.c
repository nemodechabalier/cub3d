/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:43:22 by clmanouk          #+#    #+#             */
/*   Updated: 2024/12/13 16:22:55 by nde-chab         ###   ########.fr       */
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
