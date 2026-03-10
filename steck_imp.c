/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steck_imp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <rovnania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:30:07 by rovnania          #+#    #+#             */
/*   Updated: 2026/03/10 18:01:42 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*get_stack_a(int arr[], int len)
{
	t_stack_node	*a;
	t_stack_node	*tmp;
	t_stack_node	*prev_node;
	int				i;

	i = 0;
	a = lstnew_node(arr[i], i, len);
	i++;
	prev_node = a;
	while (i < len)
	{
		tmp = lstnew_node(arr[i], i, len);
		if (!tmp)
		{
			del_stack(a);
			free(arr);
			exit(1);
		}
		prev_node->next = tmp;
		tmp->prev = prev_node;
		prev_node = tmp;
		i++;
	}
	return (a);
}

t_stack_node	*lstnew_node(int number, int i, int len)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
	{
		free(new_node);
		ft_putendl_fd("Error", 2);
		return (NULL);
	}
	new_node->value = number;
	new_node->position = i;
	new_node->stack_size = len;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}


void	del_stack(t_stack_node *lst)
{
	t_stack_node	*tmp;

	while (lst)
	{
		tmp = lst->prev;
		free(lst);
		lst = tmp;
	}
}
