/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:20:28 by saylital          #+#    #+#             */
/*   Updated: 2024/05/08 12:33:13 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (*haystack != '\0' && i < n)
	{
		if (*haystack == *needle)
		{
			while (needle[j] && haystack[j] == needle[j] && i < n)
			{
				j++;
				i++;
			}
			if (needle[j] == '\0')
				return ((char *)haystack);
		}
		haystack++;
		i++;
	}
	return (NULL);
}
