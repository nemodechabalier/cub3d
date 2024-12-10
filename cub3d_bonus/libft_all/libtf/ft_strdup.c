/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:41:28 by nde-chab          #+#    #+#             */
/*   Updated: 2024/05/20 11:52:30 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*dest;

	size = (ft_strlen(s) + 1);
	dest = malloc(sizeof(char) * size);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, s, size);
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*c;

	c = "hkwckwbc";
	(printf("%s", ft_strdup(c)));
	return (0);
}
*/