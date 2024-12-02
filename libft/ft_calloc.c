/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:14:36 by saylital          #+#    #+#             */
/*   Updated: 2024/05/06 13:51:52 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total_size;

	total_size = count * size;
	if (count > 0 && size > 0 && total_size / size != count)
		return (NULL);
	ptr = (void *)malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	ft_memset (ptr, 0, total_size);
	return (ptr);
}
