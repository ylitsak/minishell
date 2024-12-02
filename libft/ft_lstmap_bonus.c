/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:14:22 by saylital          #+#    #+#             */
/*   Updated: 2024/05/08 14:18:10 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*newlist;
	void	*data;

	newlist = NULL;
	while (lst != NULL)
	{
		data = f(lst->content);
		temp = ft_lstnew(data);
		if (temp == NULL)
		{
			ft_lstclear(&newlist, (del));
			del(data);
		}
		ft_lstadd_back(&newlist, temp);
		lst = lst->next;
	}
	return (newlist);
}
