/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:43:22 by clmanouk          #+#    #+#             */
/*   Updated: 2024/11/13 16:10:03 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (printf("wrong nb args\n"), -1);
	take_file(av[1]);
	return (0);
}