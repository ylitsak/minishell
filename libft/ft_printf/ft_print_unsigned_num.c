/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_num.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:33:29 by saylital          #+#    #+#             */
/*   Updated: 2024/06/05 12:46:02 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	calculate_length(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_print_unsigned_num(unsigned int n)
{
	int				i;
	unsigned int	num;

	i = calculate_length(n);
	if (n >= 10)
	{
		if (ft_print_unsigned_num(n / 10) == -1)
			return (-1);
	}
	num = n % 10 + '0';
	if (ft_putchar(num) == -1)
		return (-1);
	return (i);
}
