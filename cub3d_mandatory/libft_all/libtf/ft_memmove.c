/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:58:04 by nde-chab          #+#    #+#             */
/*   Updated: 2024/05/18 17:00:41 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	t_byte	*ptdest;
	t_byte	*ptsrc;

	i = 0;
	ptdest = (t_byte *)dest;
	ptsrc = (t_byte *)src;
	if (ptsrc < ptdest)
		i = n;
	while (i != 0)
	{
		ptdest[i - 1] = ptsrc[i - 1];
		i--;
	}
	if (ptsrc > ptdest)
		ft_memcpy(ptdest, ptsrc, n);
	return (dest);
}
