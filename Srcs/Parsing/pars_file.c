/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:44:16 by nde-chab          #+#    #+#             */
/*   Updated: 2024/11/12 19:01:36 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

void	free_empty(char **strs)
{
	int	i;
	int	j;

	i = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (strs[j])
			
		}
	}
}

t_file	*take_file(char *strs)
{
	t_file	*file;

	file = malloc(sizeof(t_file));
	if (!file)
		return (NULL);
}
