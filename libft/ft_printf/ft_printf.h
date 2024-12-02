/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 09:10:52 by saylital          #+#    #+#             */
/*   Updated: 2024/06/25 11:58:00 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "../libft.h"

int	ft_printf(const char *string, ...);
int	ft_putchar(char c);
int	ft_print_str(char *str);
int	ft_print_num(int n);
int	ft_print_unsigned_num(unsigned int n);
int	ft_print_hexadeci(unsigned long n, char s);
int	ft_print_pointer(void *ptr);

#endif