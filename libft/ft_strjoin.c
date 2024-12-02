/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:11:31 by saylital          #+#    #+#             */
/*   Updated: 2024/05/07 09:51:10 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	stringsize1;
	size_t	stringsize2;
	size_t	i;
	size_t	j;
	char	*ptr;

	stringsize1 = ft_strlen(s1);
	stringsize2 = ft_strlen(s2);
	i = 0;
	j = 0;
	ptr = malloc((stringsize1 + stringsize2 + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}
