/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 12:25:31 by rovnania          #+#    #+#             */
/*   Updated: 2026/02/07 20:09:56 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list_ptr;
	t_list	*new_node;
	t_list	*new_list;
	void	*tmp_cont;

	if (!lst || !f || !del)
		return (NULL);
	list_ptr = lst;
	new_list = NULL;
	while (list_ptr)
	{
		tmp_cont = f(list_ptr->content);
		new_node = ft_lstnew(tmp_cont);
		if (!new_node)
		{
			del(tmp_cont);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		list_ptr = list_ptr->next;
	}
	return (new_list);
}
