/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:12:00 by nde-chab          #+#    #+#             */
/*   Updated: 2024/06/26 19:05:17 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_count(char *s, int *size)
{
	size_t	i;

	i = 0;
	if (!s)
		return (ft_putstr_count("(null)", size));
	while (s[i])
	{
		ft_putchar_count(s[i], size);
		i++;
	}
}
