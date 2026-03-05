/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 19:13:22 by rovnania          #+#    #+#             */
/*   Updated: 2026/03/05 16:10:42 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	ft_parser(char const *argv[], int);
int	num_check(char const *str);

int main(int argc, char const *argv[])
{
	if (argc == 1)
		return (0);
	printf("count of nuumbers: %d\n", ft_parser(argv, argc));
	return (0);
}

int	ft_parser(char const *argv[], int argc)
{
	int	i;
	int	j;
	int k;
	
	k = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		if (ft_isdigit(argv[i][j]) || (argv[i][j] == '-' && ft_isdigit(argv[i][j + 1])))
		{
			k++;
			j++;
		}
		
		if (!num_check(argv[i]))
			return (0);
		i++;
	}
	return (k);
}

int	num_check(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}
int	flag_check(char const *argv)
{
	if (ft_memcmp(argv, "--adaptive", 11))
		return (1);
	else if (ft_memcmp(argv, "--simple", 9))
		return (2);
	else if (ft_memcmp(argv, "--medium", 9))
		return (3);
	else if (ft_memcmp(argv, "--complex", 10))
		return (4);
	else
		return (0);
}

int	bench_check(char const *argv)
{
	if (ft_memcmp(argv, "--bench", 8))
		return (1);
	return (0);
}
