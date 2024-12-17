/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:35:41 by nde-chab          #+#    #+#             */
/*   Updated: 2024/06/26 19:05:05 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr_count(unsigned int n, int *size)
{
	long	nb;

	nb = n;
	if (nb > 9)
	{
		ft_putnbr_count(nb / 10, size);
		ft_putchar_count(nb % 10 + '0', size);
	}
	else
		ft_putchar_count(nb + '0', size);
}
