/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steck_imp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:30:07 by rovnania          #+#    #+#             */
/*   Updated: 2026/03/10 16:27:09 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*get_stack_a(int arr[], int len)
{
	t_stack_node	*a;
	t_stack_node	*tmp;
	int				i;

	i = 0;
	a = NULL;
	while (i < len)
	{
		tmp =  malloc(sizeof(t_stack_node));
		if (!tmp)
		{
			// must free list
			exit (1);
		}
		tmp->value = arr[i];
		tmp->position = i;
		tmp->stack_size = len;
		tmp->prev = a;
		tmp->next = NULL;
		a->next = tmp;
		a = tmp;
		i++;
	}	
	return (a);
}
void	del_stack(t_stack_node *lst)
{
	t_stack_node	*tmp;
	
	while (lst)
	{
		lst->prev = tmp;
		free(lst);
		lst = tmp; 	
	}
}