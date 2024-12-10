/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:47:13 by nde-chab          #+#    #+#             */
/*   Updated: 2024/05/24 10:54:49 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*alloc;
	size_t	totsize;

	if (elementCount == 0 || elementSize == 0)
		return (malloc(0));
	totsize = elementCount * elementSize;
	if (totsize / elementCount != elementSize)
		return (NULL);
	alloc = malloc(totsize);
	if (!alloc)
		return (NULL);
	ft_bzero(alloc, totsize);
	return (alloc);
}
