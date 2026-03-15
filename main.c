/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 19:13:22 by rovnania          #+#    #+#             */
/*   Updated: 2026/03/13 15:27:51 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack_node *head)
{
	t_stack_node	*current;

	current = head;
	printf("Stack Trace:\n");
	while (current != NULL)
	{
		printf("[Val: %d ]", current->value);
		if (current->next != NULL)
			printf(" <=> ");
		else
			printf(" -> NULL\n");
		current = current->next;
	}
}

int	main(int argc, char *argv[])
{
	t_strat				flags;
	t_stack_node		*a;
	t_stack_node		*b;
	float				disorder;

	a = args_parsing(argc, argv, &flags, &disorder);
	b = NULL;
	printf("disorder is: %f\n", disorder);
	print_stack(a);
	ra(&a);
	print_stack(a);
	rra(&a);
	print_stack(a);
	return (0);
}

t_stack_node	*args_parsing(int argc, char **argv, t_strat *flags, float *dis)
{
	int				k;
	int				num_count;
	int				*arr;
	t_stack_node	*a;

	if (argc == 1)
		exit(0);
	k = comp_flag_check(argc, argv, flags);
	if (k == -1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	num_count = preparser_check(argv, k, argc);
	if (!num_count)
		return (NULL);
	arr = parser(argv, k, argc, num_count);
	if (!arr)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	a = get_stack_a(arr, num_count);
	*dis = calculate_disorder(arr, num_count);
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
