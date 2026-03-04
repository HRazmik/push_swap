/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 08:52:17 by rovnania          #+#    #+#             */
/*   Updated: 2026/02/07 20:10:27 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*ptr_d;
	const unsigned char	*ptr_s;

	i = 0;
	ptr_d = (unsigned char *)dest;
	ptr_s = (const unsigned char *)src;
	if (ptr_d == ptr_s || n == 0)
		return (dest);
	if (ptr_d < ptr_s)
	{
		while (i < n)
		{
			ptr_d[i] = ptr_s[i];
			i++;
		}
		return (dest);
	}
	while (n-- > 0)
		ptr_d[n] = ptr_s[n];
	return (dest);
}
