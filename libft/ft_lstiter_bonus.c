/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:57:15 by saylital          #+#    #+#             */
/*   Updated: 2024/05/07 09:20:15 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*iter_list;
	t_list	*temp;

	iter_list = lst;
	while (iter_list != NULL)
	{
		temp = iter_list->next;
		f(iter_list->content);
		iter_list = temp;
	}
}
