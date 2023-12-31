/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:02:36 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/24 18:42:36 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*current;
	t_list	*new_elmt;

	if (!lst || !del)
		return (0);
	res = 0;
	current = lst;
	while (current)
	{
		new_elmt = ft_lstnew(f(current->content));
		if (!new_elmt)
		{
			ft_lstclear(&res, del);
			return (0);
		}
		ft_lstadd_back(&res, new_elmt);
		current = current->next;
	}
	return (res);
}
