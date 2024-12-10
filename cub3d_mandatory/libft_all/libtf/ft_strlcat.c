/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:14:40 by nde-chab          #+#    #+#             */
/*   Updated: 2024/05/20 18:52:23 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	sl;
	size_t	dl;
	size_t	i;

	sl = ft_strlen(src);
	dl = ft_strlen(dest);
	i = 0;
	if (size <= dl)
		return (size + sl);
	while (src[i] && (dl + i) < size - 1)
	{
		dest[i + dl] = src[i];
		i++;
	}
	dest[i + dl] = '\0';
	return (dl + sl);
}
