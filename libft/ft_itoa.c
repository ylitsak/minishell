/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:19:14 by saylital          #+#    #+#             */
/*   Updated: 2024/05/13 11:39:06 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*set_zero(void)
{
	char	*string_zero;

	string_zero = malloc(2 * sizeof(char));
	if (string_zero == NULL)
		return (NULL);
	string_zero[0] = '0';
	string_zero[1] = '\0';
	return (string_zero);
}

static int	calculate_length(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i = 1;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*number_to_string(char *numbers, long num, int len)
{
	long	convert_num;
	long	starting_index;

	numbers[len] = '\0';
	starting_index = len - 1;
	if (num < 0)
	{
		num = -num;
		numbers[0] = '-';
	}
	while (num != 0)
	{
		convert_num = num % 10;
		numbers[starting_index] = convert_num + '0';
		num = num / 10;
		starting_index--;
	}
	return (numbers);
}

char	*ft_itoa(int n)
{
	int		num_len;
	char	*nums_array;
	long	number;

	number = n;
	if (n == 0)
	{
		nums_array = set_zero();
		return (nums_array);
	}
	num_len = calculate_length(number);
	nums_array = malloc((num_len + 1) * sizeof(char));
	if (nums_array == NULL)
		return (NULL);
	nums_array = number_to_string(nums_array, number, num_len);
	return (nums_array);
}
