/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:19:10 by rovnania          #+#    #+#             */
/*   Updated: 2026/03/17 12:00:48 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	preparser_check(char **argv, int start_arg, int argc)
{
	int	i;
	int	numbers_count;

	numbers_count = 0;
	i = start_arg + 1;
	while (i < argc)
	{
		if (!num_check(argv[i], &numbers_count))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	return (numbers_count);
}

int	num_check(char *str, int *numbers_count)
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
			(*numbers_count)++;
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
	int	j;

	j = 0;
	i = start_arg + 1;
	arr = malloc(arr_len * sizeof(int));
	if (!arr)
		return (NULL);
	while (i < argc)
	{
		if (!numbers_separator(argv, arr, i, &j))
		{
			free(arr);
			return (NULL);
		}
		i++;
	}
	return (arr);
}

int	numbers_separator(char **argv, int *arr, int i, int *j)
{
	char		**buff;

	if (!ft_strchr(argv[i], ' '))
	{
		if (!isinteger(argv[i]) || !repeating_num_check(arr, *j, argv[i]))
			return (0);
		arr[(*j)++] = ft_atoi(argv[i++]);
	}
	else
	{
		buff = ft_split(argv[i], ' ');
		while (*buff)
		{
			if (!isinteger(*buff) || !repeating_num_check(arr, *j, *buff))
				return (0);
			arr[(*j)++] = ft_atoi(*buff);
			buff++;
		}
		ft_free(buff);
	}
	return (1);
}
