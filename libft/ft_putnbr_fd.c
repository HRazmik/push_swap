/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 11:38:19 by rovnania          #+#    #+#             */
/*   Updated: 2026/02/11 14:25:31 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_size(unsigned int nb)
{
	unsigned int	size;

	size = 0;
	while (nb > 0)
	{
		size++;
		nb = nb / 10;
	}
	return (size);
}

static unsigned int	ft_10(unsigned int n_size)
{
	unsigned int	denominator;

	denominator = 1;
	while (n_size > 1)
	{
		denominator *= 10;
		n_size--;
	}
	return (denominator);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;
	unsigned int	den;

	if (n == 0)
		ft_putchar_fd('0', fd);
	else
	{
		if (n < 0)
		{
			num = -n;
			ft_putchar_fd('-', fd);
		}
		else
			num = n;
		den = ft_10(ft_size(num));
		while (den > 0)
		{
			ft_putchar_fd(num / den + '0', fd);
			num %= den;
			den /= 10;
		}
	}
}
