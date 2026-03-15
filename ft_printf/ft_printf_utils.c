/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:37:58 by rovnania          #+#    #+#             */
/*   Updated: 2026/02/28 12:58:19 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_size(long *nb)
{
	unsigned int	size;
	unsigned int	num;

	size = 0;
	if (*nb == 0)
		return (1);
	if (*nb < 0)
	{
		*nb *= -1;
		size++;
	}
	num = *nb;
	while (num > 0)
	{
		size++;
		num /= 10;
	}
	return (size);
}

static unsigned int	ft_10(unsigned int n_size, int n)
{
	unsigned int	denominator;

	denominator = 1;
	if (n < 0)
		n_size--;
	while (n_size > 1)
	{
		denominator *= 10;
		n_size--;
	}
	return (denominator);
}

char	*ft_sitoa(int n)
{
	long			num;
	unsigned int	den;
	unsigned int	len;
	char			*str;

	num = n;
	len = ft_size(&num);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	den = ft_10(len, n);
	len = 0;
	if (n < 0)
		str[len++] = '-';
	while (den > 0)
	{
		str[len++] = num / den + '0';
		num %= den;
		den /= 10;
	}
	str[len] = '\0';
	return (str);
}

char	*ft_uitoa(unsigned int n)
{
	long			num;
	unsigned int	den;
	unsigned int	len;
	char			*str;

	num = n;
	len = ft_size(&num);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	den = ft_10(len, 1);
	len = 0;
	while (den > 0)
	{
		str[len++] = num / den + '0';
		num %= den;
		den /= 10;
	}
	str[len] = '\0';
	return (str);
}
