/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:21:49 by rovnania          #+#    #+#             */
/*   Updated: 2026/02/07 20:12:01 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	l;
	size_t	j;

	j = 0;
	i = 0;
	l = 0;
	while (little[l])
		l++;
	if (l == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && i + j < len && big[i + j] == little[j])
		{
			if (l == j + 1)
			{
				return ((char *)&(big[i]));
			}
			j++;
		}
		i++;
	}
	return (0);
}
