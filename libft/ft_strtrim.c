/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:20:37 by saylital          #+#    #+#             */
/*   Updated: 2024/05/13 10:45:38 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	trimchars(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		j;
	const char	*endptr;
	char		*trimptr;

	if (!s1)
		return (NULL);
	endptr = s1 + ft_strlen(s1) - 1;
	j = 0;
	while (*s1 != '\0' && trimchars(*s1, set))
		s1++;
	while (endptr >= s1 && trimchars(*endptr, set))
		endptr--;
	i = (endptr - s1) + 1;
	trimptr = malloc((i + 1) * sizeof(char));
	if (trimptr == NULL)
		return (NULL);
	while (j < i)
	{
		trimptr[j] = s1[j];
		j++;
	}
	trimptr[j] = '\0';
	return (trimptr);
}
