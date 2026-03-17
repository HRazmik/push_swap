/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:43:08 by rovnania          #+#    #+#             */
/*   Updated: 2026/02/28 13:17:12 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_swap(char *s)
{
	int		l;
	int		i;
	char	tmp;

	i = 0;
	l = 0;
	while (s[l])
		l++;
	l--;
	while (i < l)
	{
		tmp = s[i];
		s[i] = s[l];
		s[l] = tmp;
		i++;
		l--;
	}
	return (s);
}

int	ft_print_ptr(void *ptr)
{
	char			*str;
	char			*hex_lower;
	unsigned long	num_2;
	int				len;

	len = 0;
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	num_2 = (unsigned long)ptr;
	hex_lower = "0123456789abcdef";
	while (num_2 > 0)
	{
		num_2 /= 16;
		len++;
	}
	num_2 = (unsigned long)ptr;
	str = ft_hex(num_2, len, hex_lower);
	if (write(1, "0x", 2) == -1)
		return (-1);
	return (ft_putstr(str, 1) + 2);
}

int	ft_print_hex(unsigned int num, int baza)
{
	char			*hex_lower;
	char			*hex_upper;
	int				len;
	unsigned long	num_2;

	num_2 = num;
	len = 0;
	hex_lower = "0123456789abcdef";
	hex_upper = "0123456789ABCDEF";
	while (num_2 > 0)
	{
		num_2 /= 16;
		len++;
	}
	if (len == 0)
		return (write(1, "0", 1));
	if (baza == 1)
		return (ft_putstr(ft_hex(num, len, hex_lower), 1));
	else
		return (ft_putstr(ft_hex(num, len, hex_upper), 1));
}

char	*ft_hex(unsigned long num, int len, char *base)
{
	char			*hex_str;
	int				i;

	i = 0;
	hex_str = malloc(sizeof(char) *(len + 1));
	if (!hex_str)
		return (NULL);
	while (num)
	{
		hex_str[i++] = base[num % 16];
		num /= 16;
	}
	hex_str[i] = '\0';
	return (str_swap(hex_str));
}
