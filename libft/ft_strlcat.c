/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 08:52:55 by rovnania          #+#    #+#             */
/*   Updated: 2026/02/07 20:11:47 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	d;
	size_t	l;
	size_t	sum;

	l = 0;
	d = 0;
	while (dest[d])
		d++;
	while (src[l])
		l++;
	if (d >= size)
		return (l + size);
	else
		sum = d + l;
	l = 0;
	while (size - 1 > d && src[l])
	{
		dest[d] = src[l];
		d++;
		l++;
	}
	dest[d] = '\0';
	return (sum);
}
