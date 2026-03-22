/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 19:13:22 by rovnania          #+#    #+#             */
/*   Updated: 2026/03/22 17:08:42 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// add to header
void	sort_hard(t_stack *a, t_stack *b, t_count_opers *op, t_strat flags)
{
	if (flags.simple)
		insertion_sort(&a, &b, op, stack_size(&a));
	else if (flags.medium)
		medium_sort(&a, &b, op, stack_size(&a));
	else if (flags.complex)
		radix_sort(&a, &b, op, stack_size(&a));
}

int	main(int argc, char *argv[])
{
	t_strat			flags;
	t_stack			*a;
	t_stack			*b;
	float			disorder;
	t_count_opers	op;

	a = args_pars(argc, argv, &flags, &disorder);
	b = NULL;
	set_opers_zero(&op);
	if (!flags.adaptive)
		sort_hard(a, b, &op, flags);
	else
	{
		if (disorder < 0.2)
			insertion_sort(&a, &b, &op, stack_size(&a));
		else if (disorder < 0.5)
			medium_sort(&a, &b, &op, stack_size(&a));
		else
			radix_sort(&a, &b, &op, stack_size(&a));
	}
	if (flags.bench)
		bench(disorder, op, flags);
	del_stack(&a);
	ft_printf("thiss = %p\n", a);
	del_stack(&b);
	return (0);
}

// add to header
void	write_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

t_stack	*args_pars(int argc, char **argv, t_strat *flags, float *dis)
{
	int		k;
	int		num_count;
	int		*arr;
	t_stack	*a;

	if (argc == 1)
		exit(0);
	k = comp_flag_check(argc, argv, flags);
	if (k == -1)
		write_exit();
	num_count = preparser_check(argv, k, argc);
	if (!num_count)
		return (NULL);
	arr = parser(argv, k, argc, num_count);
	if (!arr)
		write_exit();
	a = get_stack_a(arr, num_count);
	*dis = calculate_disorder(arr, num_count);
	assign_index(a, num_count);
	free(arr);
	return (a);
}

void	inicial_tflag(t_strat *flags)
{
	flags->simple = 0;
	flags->medium = 0;
	flags->complex = 0;
	flags->adaptive = 0;
	flags->bench = 0;
}
