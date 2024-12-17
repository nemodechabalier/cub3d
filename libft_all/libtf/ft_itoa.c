/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:48:38 by nde-chab          #+#    #+#             */
/*   Updated: 2024/05/23 17:11:01 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_size(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			i;
	long int	nb;
	char		*itoa;

	i = ft_count_size(n);
	nb = n;
	if (nb < 0)
		nb = -nb;
	if (i == 0)
		i++;
	itoa = (char *)ft_calloc(i + 1, 1);
	if (!itoa)
		return (NULL);
	itoa[i--] = 0;
	while (nb != 0)
	{
		itoa[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n == 0)
		itoa[i] = '0';
	if (n < 0)
		itoa[i] = '-';
	return (itoa);
}
/*
int main(void)
{
    printf("%s\n", ft_itoa(-2147483648LL));
    return (0);
}*/