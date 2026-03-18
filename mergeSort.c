/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:45:09 by narehakobya       #+#    #+#             */
/*   Updated: 2026/03/18 19:59:36 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_size(t_stack *k)
{
    int len = 0;
    while (k)
    {
        len++;
        k = k->next;
    }
    return (len);
}


void divide(t_stack **a, t_stack **b)
{
    int i = 0;
    int size = stack_size(*a);
    while (i < size / 2)
    {
        pb(a, b);
        i++;
    }
}

void merge(t_stack **a, t_stack **b)
{
    int size;
    int i;
    while (*b)
    {
        size = stack_size(*a);
        i = 0;
        while (i < size && (*a)->value < (*b)->value)
        {
            ra(a);
            i++;
        }
        pa(b, a);
    }
}

void final_rotate(t_stack **a)
{
    int min = find_min(*a);
    while ((*a)->value != min)
        ra(a);
}

void merge_sort(t_stack **a, t_stack **b)
{
    int size = stack_size(*a);
    if (size <= 1)
        return;
    divide(a, b);
    merge_sort(a, b);
    merge_sort(b, a);
    merge(a, b);
}
