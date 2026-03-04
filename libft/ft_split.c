/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 09:54:13 by rovnania          #+#    #+#             */
/*   Updated: 2026/02/07 20:11:16 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_counter(const char *str, char c)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static char	**ft_free_all(char **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		start;

	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (word_counter(s, c) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (i < (int)word_counter(s, c))
	{
		while (s[j] && s[j] == c)
			j++;
		start = j;
		while (s[j] && s[j] != c)
			j++;
		arr[i] = ft_substr(s, start, j - start);
		if (!arr[i++])
			return (ft_free_all(arr, i - 1));
	}
	arr[i] = NULL;
	return (arr);
}
