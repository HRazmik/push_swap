/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 19:13:22 by rovnania          #+#    #+#             */
/*   Updated: 2026/03/09 19:32:06 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_flags(t_flag *yyy)
{
	printf("simple: %d\n", yyy->simple);
	printf("medium: %d\n", yyy->medium);
	printf("complex: %d\n", yyy->complex);
	printf("adaptive: %d\n", yyy->adaptive);
	printf("bench: %d\n", yyy->bench);
}

void	inicial_tflag(t_flag *yyy)
{
	yyy->simple = 0;
	yyy->medium = 0;
	yyy->complex = 0;
	yyy->adaptive = 0;
	yyy->bench = 0;
}

int	main(int argc, char *argv[])
{
	t_flag	yyy;
	int		k;
	int		num_count;
	int		*arr;

	if (argc == 1)
		return (0);
	k = comp_flag_check(argc, argv, &yyy);
	if (k == -1)
	{
		printf("error occurd\n");
		return (1);
	}
	num_count = preparser_check(argv, k, argc);
	if (!num_count)
		return (1);
	arr = parser(argv, k, argc, num_count);
	if (!arr)
	{
		printf("error\n");
		return (1);
	}
	for (int i = 0; i < num_count; i++)
		printf("num: %d\n", arr[i]);
	return (0);
}

int	tflag_check(t_flag *yyy, int flag_count)
{
	int	k;

	k = 0;
	if (yyy->adaptive)
		k++;
	if (yyy->complex)
		k++;
	if (yyy->medium)
		k++;
	if (yyy->simple)
		k++;
	if (k > 1)
		return (-1);
	if (yyy->bench)
		k++;
	if (k && k != flag_count)
		return (-1);
	return (k);
}

int	comp_flag_check(int argc, char **argv, t_flag *yyy)
{
	int	flags_count;
	int	i;

	i = 1;
	flags_count = 0;
	inicial_tflag(yyy);
	while (i <= 2 && i < argc)
	{
		if (!ft_memcmp(argv[i], "--adaptive", 11))
			yyy->adaptive = (bool)++flags_count;
		else if (!ft_memcmp(argv[i], "--simple", 9))
			yyy->simple = (bool)++flags_count;
		else if (!ft_memcmp(argv[i], "--medium", 9))
			yyy->medium = (bool)++flags_count;
		else if (!ft_memcmp(argv[i], "--complex", 10))
			yyy->complex = (bool)++flags_count;
		if (!ft_memcmp(argv[i], "--bench", 8))
			yyy->bench = (bool)++flags_count;
		i++;
	}
	return (tflag_check(yyy, flags_count));
}
