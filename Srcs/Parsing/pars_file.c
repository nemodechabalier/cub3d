/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:44:16 by nde-chab          #+#    #+#             */
/*   Updated: 2024/11/12 19:46:14 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

int	ft_empty(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_file	*take_file(char **strs)
{
	t_file	*file;

	file = malloc(sizeof(t_file));
	if (!file)
		return (NULL);
	
}
