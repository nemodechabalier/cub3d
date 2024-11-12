/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:54:06 by nde-chab          #+#    #+#             */
/*   Updated: 2024/05/20 12:17:18 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*little)
		return ((char *)big);
	while (big[i] && i + j < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			if (little[j + 1] == 0)
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

/*
#include <bsd/string.h>
#include <stdio.h>

int	main(void)
{
	char	*str;
	char	*str2;
	char	*ptr;

	str = "FOO BAR BAZ";
	str2 = "BAR";
	ptr = ft_strnstr(str,str2,7);
	printf("ft_strnstr : %s \n", ptr);
	ptr = strnstr(str,str2,30);
	printf("strnstr : %s \n", ptr);
}
*/