/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:01:15 by nde-chab          #+#    #+#             */
/*   Updated: 2024/05/21 16:43:33 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t size)
{
	size_t	i;
	t_byte	*pts;
	t_byte	ptc;

	i = 0;
	pts = (t_byte *)s;
	ptc = (t_byte)c;
	while (i < size)
	{
		if (pts[i] == ptc)
			return ((void *)(pts + i));
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int					data[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	const unsigned int	size = 700 * 4;
	char				*found;
	char				*found2;

	found = memchr(data, 57, size);
	found2 = ft_memchr(data, 57, size);
	printf("original : %s\n" , found);
	printf("adresse :%p\n", found);
	printf("fonction : %s\n", found2);
	printf("adresse : %p\n", found2);
	found = memchr(data, 51, size);
	found2 = ft_memchr(data, 51, size);
	printf("original : %s\n" , found);
	printf("adresse :%p\n", found);
	printf("fonction : %s\n", found2);
	printf("adresse : %p\n", found2);
	return (0);
}
*/