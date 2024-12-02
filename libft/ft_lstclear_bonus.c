/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:26:15 by saylital          #+#    #+#             */
/*   Updated: 2024/05/06 14:11:30 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*rmv_list;
	t_list	*temp;

	rmv_list = *lst;
	while (rmv_list != NULL)
	{
		temp = rmv_list->next;
		del(rmv_list->content);
		free(rmv_list);
		rmv_list = temp;
	}
	*lst = NULL;
}
