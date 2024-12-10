/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:40:25 by nde-chab          #+#    #+#             */
/*   Updated: 2024/06/26 19:05:39 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_count(long n, int *size)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar_count('-', size);
	}
	if (nb > 9)
	{
		ft_putnbr_count(nb / 10, size);
		ft_putchar_count(nb % 10 + '0', size);
	}
	else
		ft_putchar_count(nb + '0', size);
}
