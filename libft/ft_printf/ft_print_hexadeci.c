/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadeci.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:50:57 by saylital          #+#    #+#             */
/*   Updated: 2024/06/05 12:45:37 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	print_hex_recursive(unsigned long num, char *base)
{
	if (num >= 16)
	{
		if (print_hex_recursive(num / 16, base) == -1)
			return (-1);
	}
	if (ft_putchar(base[num % 16]) == -1)
		return (-1);
	return (0);
}

static int	calculate_length(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	ft_print_hexadeci(unsigned long num, char s)
{
	char	*lower_hex;
	char	*upper_hex;
	int		count;

	lower_hex = "0123456789abcdef";
	upper_hex = "0123456789ABCDEF";
	count = calculate_length(num);
	if (num == 0)
	{
		return (ft_putchar('0'));
	}
	if (s == 'X')
	{
		if (print_hex_recursive(num, upper_hex) == -1)
			return (-1);
	}
	else
	{
		if (print_hex_recursive(num, lower_hex) == -1)
			return (-1);
	}
	return (count);
}
