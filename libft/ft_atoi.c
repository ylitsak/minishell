/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:03:01 by saylital          #+#    #+#             */
/*   Updated: 2024/05/08 09:32:42 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int		neg;
	long	num;
	long	check;

	neg = 1;
	num = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		check = num;
		num = (*str - '0') + num * 10;
		if (num / 10 != check && neg == -1)
			return (0);
		if (num / 10 != check && neg == 1)
			return (-1);
		str++;
	}
	return (num * neg);
}
