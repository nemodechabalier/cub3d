/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:23:08 by nde-chab          #+#    #+#             */
/*   Updated: 2024/05/21 18:58:59 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t sz)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < sz)
	{
		if (s1[i] != s2[i])
			return ((t_byte)s1[i] - (t_byte)s2[i]);
		i++;
	}
	return (0);
}
