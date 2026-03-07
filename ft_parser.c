/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 13:35:23 by rovnania          #+#    #+#             */
/*   Updated: 2026/03/06 19:26:31 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_parser(char **argv, int argc)
{
	int i;
	int	j;
	int	k;

	k = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		if (ft_isdigit(argv[i][j]) ||
			(argv[i][j] == '-' && ft_isdigit(argv[i][j + 1])) ||
			(argv[i][j] == '+' && ft_isdigit(argv[i][j + 1])))
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

int	num_check(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' && ft_isdigit(str[i + 1])) ||
		(str[i] == '+' && ft_isdigit(str[i + 1])))
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else if ()
		{
			
		}
		else
			return (0);
	}
	return (1);
}
