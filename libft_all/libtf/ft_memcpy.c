/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:45:29 by nde-chab          #+#    #+#             */
/*   Updated: 2024/05/22 11:37:08 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	t_byte	*ptsrc;
	t_byte	*ptdest;

	if (dest == src)
		return (dest);
	i = 0;
	ptsrc = (t_byte *)src;
	ptdest = (t_byte *)dest;
	while (i < n)
	{
		ptdest[i] = ptsrc[i];
		i++;
	}
	return ((void *)ptdest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("%s",(char *)memcpy(((void *)0), ((void *)0), 3));
	return (0);
}*/