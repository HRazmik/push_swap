/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 19:32:33 by rovnania          #+#    #+#             */
/*   Updated: 2026/03/21 19:34:48 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_opers_zero(t_count_opers *op)
{
	op->sa = 0;
	op->sb = 0;
	op->ss = 0;
	op->pa = 0;
	op->pb = 0;
	op->ra = 0;
	op->rb = 0;
	op->rr = 0;
	op->rra = 0;
	op->rrb = 0;
	op->rrr = 0;
}

int	tflag_check(t_strat *flags, int flag_count)
{
	int	k;

	k = 0;
	if (flags->adaptive)
		k++;
	if (flags->complex)
		k++;
	if (flags->medium)
		k++;
	if (flags->simple)
		k++;
	if (k > 1)
		return (-1);
	if (flags->bench)
		k++;
	if (k && k != flag_count)
		return (-1);
	if (k == 0 || (k == 1 && flags->bench))
		flags->adaptive = 1;
	return (k);
}

int	comp_flag_check(int argc, char **argv, t_strat *flags)
{
	int	flags_count;
	int	i;

	i = 1;
	flags_count = 0;
	inicial_tflag(flags);
	while (i <= 2 && i < argc)
	{
		if (!ft_memcmp(argv[i], "--adaptive", 11))
			flags->adaptive = (bool)++flags_count;
		else if (!ft_memcmp(argv[i], "--simple", 9))
			flags->simple = (bool)++flags_count;
		else if (!ft_memcmp(argv[i], "--medium", 9))
			flags->medium = (bool)++flags_count;
		else if (!ft_memcmp(argv[i], "--complex", 10))
			flags->complex = (bool)++flags_count;
		if (!ft_memcmp(argv[i], "--bench", 8))
			flags->bench = (bool)++flags_count;
		i++;
	}
	return (tflag_check(flags, flags_count));
}

void	assign_index(t_stack *a, int size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		i;

	ptr = a;
	while (ptr)
	{
		ptr->index = -1;
		ptr = ptr->next;
	}
	i = size;
	while (--i >= 0)
	{
		ptr = a;
		highest = NULL;
		while (ptr)
		{
			if (ptr->index == -1 && (highest == NULL
					|| ptr->value > highest->value))
				highest = ptr;
			ptr = ptr->next;
		}
		if (highest)
			highest->index = i;
	}
}
