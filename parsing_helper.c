/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 19:29:09 by rovnania          #+#    #+#             */
/*   Updated: 2026/03/09 19:30:28 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isinteger(char *nptr)
{
	int				i;
	long			sign;
	unsigned int	number;

	i = 0;
	sign = 1;
	number = 0;
	while (nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = (number * 10) + nptr[i] - '0';
		i++;
		if (sign * number > INT_MAX || sign * number < INT_MIN)
			return (0);
	}
	return (1);
}

int	repeating_num_check(int *arr, int j, char *str)
{
	int	i;
	int	number_to_find;

	i = 0;
	number_to_find = ft_atoi(str);
	while (i < j)
	{
		if (arr[i] == number_to_find)
			return (0);
		i++;
	}
	return (1);
}

void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
}