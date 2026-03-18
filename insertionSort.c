/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narehakobyan <narehakobyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 16:37:19 by narehakobya       #+#    #+#             */
/*   Updated: 2026/03/16 18:59:09 by narehakobya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_min(t_stack_node *a)
{
    int min;

    min = a->value;
    while (a)
    {
        if (a->value < min)
            min = a->value;
        a = a->next;
    }
    return (min);
}

void min_rotate(t_stack_node **a)
{
    int min;

    min = find_min(*a);
    while ((*a)->value != min)
        ra(a);
}

void rotate_until_position(t_stack_node **a, int value)
{
    while (*a && value > (*a)->value)
        ra(a);
}

void insertion_sort(t_stack_node **a, t_stack_node **b)
{
    while (*a)
        pb(a, b);

    while (*b)
    {
        rotate_until_position(a, (*b)->value);
        pa(a, b);
    }

    min_rotate(a);
}