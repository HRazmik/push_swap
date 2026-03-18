/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 16:37:19 by narehakobya       #+#    #+#             */
/*   Updated: 2026/03/18 20:24:33 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_min(t_stack *a)
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

void min_rotate(t_stack **a)
{
    int min;

    min = find_min(*a);
    while ((*a)->value != min)
        ra(a);
}

void rotate_until_position(t_stack **a, int value)
{
    while (*a && value > (*a)->value)
        ra(a);
}

void insertion_sort(t_stack **a, t_stack **b)
{
    while (*a)
        pb(a, b);

    while (*b)
    {
        rotate_until_position(a, (*b)->value);
        pa(a, b );
    }

    min_rotate(a);
}