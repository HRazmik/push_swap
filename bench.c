/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:13:26 by rovnania          #+#    #+#             */
/*   Updated: 2026/03/17 12:10:05 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	calculate_disorder(int arr[], int size)
{
	int	mistakes;
	int	total_pairs;
	int	j;
	int	i;

	i = 0;
	total_pairs = 0;
	mistakes = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs++;
			if (arr[i] > arr[j])
				mistakes++;
			j++;
		}
		i++;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((float)mistakes / total_pairs);
}

static char	*select_mode(t_strat flags)
{
	if (flags.adaptive)
		return (ft_strdup("adaptive"));
	else if (flags.simple)
		return (ft_strdup("simple"));
	else if (flags.medium)
		return (ft_strdup("medium"));
	else if (flags.complex)
		return (ft_strdup("complex"));
	return (NULL);
}

static char	*select_startegy(float disorder, t_strat flags)
{
	if (flags.simple)
		return (ft_strdup("O(n^2)"));
	else if (flags.medium)
		return (ft_strdup("O(n√n)"));
	else if (flags.complex)
		return (ft_strdup("O(n log n)"));
	if (disorder < 0.2)
		return (ft_strdup("O(n^2)"));
	else if (disorder >= 0.2 && disorder < 0.5)
		return (ft_strdup("O(n√n)"));
	else if (disorder >= 0.5)
		return (ft_strdup("O(n log n)"));
	return (0);
}

void	bench(float disorder, t_count_opers op, t_strat flags)
{
	int		dis;
	char	*mode;
	char	*strategy;

	strategy = NULL;
	dis = (int)(disorder * 10000);
	ft_printf("[bench] disorder:  %d.", dis / 100);
	if (dis % 100 == 0)
		ft_printf("00%%\n");
	else
		ft_printf("%d%%\n", dis % 100);
	mode = select_mode(flags);
	strategy = select_startegy(disorder, flags);
	ft_printf("[bench] strategy:  %s / %s\n", mode, strategy);
	ft_printf("[bench] total_ops %d\n", op.all_op);
	ft_printf("[bench] sa:  %d  sb:  %d  ss  %d", op.sa, op.sb, op.ss);
	ft_printf("  pa  %d  pb  %d\n", op.pa, op.pb);
	ft_printf("[bench] ra:  %d  rb:  %d  r  %d", op.ra, op.rb, op.rr);
	ft_printf("  rra  %d  rrb  %d  rrr  %d\n", op.rra, op.rrb, op.rrr);
	if (!mode)
		free(mode);
	if (strategy)
		free(strategy);
}
