/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:56:33 by saylital          #+#    #+#             */
/*   Updated: 2024/05/07 09:51:17 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	srclen;
	size_t	destlen;
	size_t	i;

	srclen = (ft_strlen(src));
	destlen = (ft_strlen(dest));
	i = 0;
	if (destsize == 0)
		return (srclen);
	if (destlen >= destsize)
		return (destsize + srclen);
	while (src[i] != '\0' && i < destsize - destlen - 1)
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (destlen + srclen);
}
