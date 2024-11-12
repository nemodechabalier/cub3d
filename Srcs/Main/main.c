/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:43:22 by clmanouk          #+#    #+#             */
/*   Updated: 2024/11/12 18:40:41 by clmanouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (printf("wrong nb args\n"), -1);
	test(av[1]);
	return (0);
}