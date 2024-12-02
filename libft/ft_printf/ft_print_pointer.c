/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:35:55 by saylital          #+#    #+#             */
/*   Updated: 2024/06/05 12:45:59 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(void *ptr)
{
	int				count;
	int				check;
	unsigned long	pointer;

	count = 0;
	pointer = (unsigned long)ptr;
	if (!pointer)
	{
		count = ft_print_str("0x0");
		if (count == -1)
			return (-1);
	}
	else
	{
		count = ft_print_str("0x");
		if (count == -1)
			return (-1);
		check = ft_print_hexadeci(pointer, 'x');
		if (check == -1)
			return (-1);
		count += check;
	}
	return (count);
}
