/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:07:52 by nde-chab          #+#    #+#             */
/*   Updated: 2024/05/22 09:46:15 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{

	char str[100000];
	char c = 0;
	for (int i = 0; i < 100000; i++)
	{
		if (!c)
			c++;
		str[i] = c;
		c++;
	}
	str[99999]=0;
	printf("%p\n", ft_strrchr(str, 2147483647));
	printf("%p", strrchr(str, 2147483647));
	return (0);
}
*/