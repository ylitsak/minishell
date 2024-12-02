/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:16:51 by saylital          #+#    #+#             */
/*   Updated: 2024/05/03 14:35:27 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lastelement;

	lastelement = lst;
	if (lastelement == NULL)
		return (NULL);
	while (lastelement-> next != NULL)
	{
		lastelement = lastelement->next;
	}
	return (lastelement);
}
