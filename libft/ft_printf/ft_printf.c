/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 09:09:49 by saylital          #+#    #+#             */
/*   Updated: 2024/06/05 12:46:04 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	function_list(va_list *args, char s)
{
	if (s == 's')
		return (ft_print_str(va_arg(*args, char *)));
	else if (s == 'i' || s == 'd')
		return (ft_print_num(va_arg(*args, int)));
	else if (s == 'u')
		return (ft_print_unsigned_num(va_arg(*args, unsigned int)));
	else if (s == 'x' || s == 'X')
		return (ft_print_hexadeci(va_arg(*args, unsigned int), s));
	else if (s == 'p')
		return (ft_print_pointer(va_arg(*args, void *)));
	else if (s == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (s == '%')
		return (ft_putchar('%'));
	return (-1);
}

static	int	check_args(va_list *args, const char *string)
{
	int	check;
	int	length;
	int	count;

	length = -1;
	count = 0;
	while (string[++length])
	{
		if (string[length] == '%' && string[length + 1] != '\0'
			&& ft_strchr("cspdiuxX%", string[length + 1]))
		{
			check = function_list(args, string[length + 1]);
			if (check == -1)
				return (-1);
			count += check;
			length++;
		}
		else if (string[length] != '%')
		{
			if (ft_putchar(string[length]) == -1)
				return (-1);
			count++;
		}
	}
	return (count);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, string);
	count = check_args(&args, string);
	if (count == -1)
		return (-1);
	va_end(args);
	return (count);
}
