/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:03:32 by nde-chab          #+#    #+#             */
/*   Updated: 2024/06/26 19:03:13 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putnbr_count(long n, int *size);
void	ft_putstr_count(char *s, int *size);
void	ft_putchar_count(char c, int *size);
void	ft_print_base(char c, unsigned long nb, int *size);
void	ft_putunbr_count(unsigned int n, int *size);
int		ft_printf(const char *str, ...) __attribute__((format(printf, 1, 2)));

#endif