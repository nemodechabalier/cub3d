/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:42:24 by nde-chab          #+#    #+#             */
/*   Updated: 2024/12/13 19:04:08 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d_bonus.h"

int	count_alloc_texture(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			j++;
		i++;
	}
	return (j);
}

int	count_word(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			n++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (n);
}

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

int	is_map(char *str)
{
	int	i;

	i = 0;
	if (ft_empty(str))
		return (FALSE);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '1')
			return (FALSE);
		i++;
	}
	return (TRUE);
}
