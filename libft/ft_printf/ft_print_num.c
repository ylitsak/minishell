/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:39:20 by saylital          #+#    #+#             */
/*   Updated: 2024/06/05 12:45:52 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	print_max_neg(void)
{
	if (write(1, "-2147483648", 11) == -1)
		return (-1);
	return (11);
}

static int	calculate_length(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_print_num(int n)
{
	int	i;
	int	num;

	i = 0;
	if (n == -2147483648)
		return (print_max_neg());
	i = calculate_length(n);
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		n = -n;
	}
	if (n >= 10)
	{
		if (ft_print_num(n / 10) == -1)
			return (-1);
	}
	num = n % 10 + '0';
	if (ft_putchar(num) == -1)
		return (-1);
	return (i);
}
