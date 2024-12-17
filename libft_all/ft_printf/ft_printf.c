/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:06:56 by nde-chab          #+#    #+#             */
/*   Updated: 2024/06/26 19:05:59 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	verif_char(char c)
{
	int		i;
	char	*conversions;

	conversions = "cspdiuxX%";
	i = 0;
	while (conversions[i])
	{
		if (conversions[i] == c)
			return (0);
		i++;
	}
	return (-1);
}

static int	verif_str(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (verif_char(str[i]) == -1 || str[i] == '\0')
				return (-1);
		}
		i++;
	}
	return (0);
}

void	ft_print_fuction(va_list args, char c, int *size)
{
	unsigned long	i;

	if (c == 'd' || c == 'i')
		ft_putnbr_count(va_arg(args, int), size);
	else if (c == 's')
		ft_putstr_count(va_arg(args, char *), size);
	else if (c == 'x' || c == 'X')
		ft_print_base(c, va_arg(args, unsigned int), size);
	else if (c == 'c')
		ft_putchar_count(va_arg(args, int), size);
	else if (c == 'p')
	{
		i = va_arg(args, unsigned long);
		if (i == 0)
			return (ft_putstr_count("(nil)", size));
		ft_putstr_count("0x", size);
		ft_print_base('x', i, size);
	}
	else if (c == 'u')
		ft_putunbr_count(va_arg(args, unsigned long), size);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	va_list	args;
	int		size;

	size = 0;
	if (!str || verif_str(str) == -1)
		return (-1);
	va_start(args, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
				ft_putchar_count('%', &size);
			else
				ft_print_fuction(args, str[i], &size);
		}
		else
			ft_putchar_count(str[i], &size);
		i++;
	}
	return (va_end(args), size);
}
