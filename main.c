/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 19:13:22 by rovnania          #+#    #+#             */
/*   Updated: 2026/03/02 19:13:17 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char const *argv[])
{
	if (argc == 1)
		return (0);
	if (flag_check(*argv))
	{
		return (10);
	}
	return (0);
}

int	flag_check(char const *argv)
{
	if (ft_memcmp(argv, "--adaptive", 11))
		return (1);
	if (ft_memcmp(*argv, "--simple", 9))
		return (2);
	if (ft_memcmp(*argv, "--medium", 9))
		return (3);
	if (ft_memcmp(*argv, "--complex", 10))
		return (4);
	if (ft_memcmp(*argv, "--brench", 9))
		return (5);
	return (0);
}