/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:32:30 by nde-chab          #+#    #+#             */
/*   Updated: 2024/05/20 16:13:11 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	t_byte	*pts1;
	t_byte	*pts2;

	i = 0;
	pts1 = (t_byte *)s1;
	pts2 = (t_byte *)s2;
	while (i < n)
	{
		if (pts1[i] != pts2[i])
			return (pts1[i] - pts2[i]);
		i++;
	}
	return (0);
}
