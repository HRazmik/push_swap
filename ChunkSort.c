/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ChunkSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:15:43 by narehakobya       #+#    #+#             */
/*   Updated: 2026/03/18 19:32:25 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_max(t_stack_node *a)
{
    int max = a->value;
    while (a)
    {
        if (a->value > max)
            max = a->value;
        a = a->next;
    }
    return (max);
}

int find_position(t_stack_node *a, int value)
{
    int i = 0;
    while (a)
    {
        if (a->value == value)
            return (i);
        i++;
        a = a->next;
    }
    return (-1);
}

int chunk_size(int n)
{
    int i = 1;
    while (i * i < n)
        i++;
    return (i);
}

void push_chunk(t_stack_node **a, t_stack_node **b, int min, int max)
{
    int size = stack_size(*a);
    int i = 0;

    while (i < size)
    {
        if ((*a)->value >= min && (*a)->value <= max)
            pb(a, b);
        else
            ra(a);
        i++;
    }
}

void push_back_max(t_stack_node **a, t_stack_node **b)
{
    int max;
    int pos;
    int size;

    while (*b)
    {
        max = find_max(*b);
        pos = find_position(*b, max);
        size = stack_size(*b);

        if (pos <= size / 2)
        {
            while ((*b)->value != max)
                rb(b);
        }
        else
        {
            while ((*b)->value != max)
                rrb(b);
        }
        pa(b, a);
    }
}

void medium_sort(t_stack_node **a, t_stack_node **b)
{
    int size;
    int chunk;
    int min;
    int start;
    int end;

    size = stack_size(*a);
    chunk = chunk_size(size);
    min = find_min(*a);

    while (*a)
    {
        start = min;
        end = min + chunk;
        push_chunk(a, b, start, end);
        min = end + 1;
    }
    push_back_max(a, b);
}