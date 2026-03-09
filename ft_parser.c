/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:19:10 by rovnania          #+#    #+#             */
/*   Updated: 2026/03/09 19:30:32 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	preparser_check(char **argv, int start_arg, int argc)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = start_arg + 1;
	while (i < argc)
	{
		j = 0;
		if (!num_check(argv[i], &k))
			return (0);
		i++;
	}
	return (k);
}

int	num_check(char *str, int *k)
{
	int	i;
	int	moving_checker;

	i = 0;
	moving_checker = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i])
			|| (str[i] == '-' && ft_isdigit(str[i + 1]))
			|| (str[i] == '+' && ft_isdigit(str[i + 1])))
		{
			i++;
			(*k)++;
		}
		while (ft_isdigit(str[i]))
			i++;
		while (str[i] && str[i] == ' ')
			i++;
		if (!str[i])
			return (1);
		if (moving_checker == i)
			break ;
		moving_checker = i;
	}
	return (0);
}

int	*parser(char **argv, int start_arg, int argc, int arr_len)
{
	int	*arr;
	int	i;

	i = start_arg + 1;
	arr = malloc(arr_len * sizeof(int));
	if (!arr)
		return (NULL);
	while (i < argc)
	{
		if (!numbers_separator(argv, arr, i))
			return (NULL);
		i++;
	}
	return (arr);
}

int	numbers_separator(char **argv, int *arr, int i)
{
	char		**buff;
	static int	j;

	if (!ft_strchr(argv[i], ' '))
	{
		if (!isinteger(argv[i]) || !repeating_num_check(arr, j, argv[i]))
			return (0);
		arr[j++] = ft_atoi(argv[i++]);
	}
	else
	{
		buff = ft_split(argv[i], ' ');
		while (*buff)
		{
			if (!isinteger(*buff) || !repeating_num_check(arr, j, *buff))
				return (0);
			arr[j++] = ft_atoi(*buff);
			buff++;
		}
		ft_free(buff);
	}
	return (1);
}


