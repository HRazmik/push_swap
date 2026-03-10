/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:46:44 by rovnania          #+#    #+#             */
/*   Updated: 2026/02/28 17:13:13 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	int		i;
	int		printed_chr;	
	int		count;
	va_list	args;

	count = 0;
	i = 0;
	va_start(args, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1])
			printed_chr = ft_print_helper(fmt[i++ + 1], args);
		else
			printed_chr = write(1, &fmt[i], 1);
		if (printed_chr == -1)
			return (-1);
		i++;
		count += printed_chr;
	}
	va_end(args);
	return (count);
}

int	ft_print_helper(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (format == 's')
		return (ft_putstr(va_arg(args, char *), 0));
	if (format == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	if (format == 'd' || format == 'i')
		return (ft_putstr(ft_sitoa(va_arg(args, int)), 1));
	if (format == 'u')
		return (ft_putstr(ft_uitoa(va_arg(args, unsigned int)), 1));
	if (format == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), 1));
	if (format == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), 2));
	if (format == '%')
		return (write(1, "%", 1));
	if (format == 'a')
		return (write(1, "hello world", 11));
	return (0);
}

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s, int flag)
{
	size_t	len;

	len = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	while (s[len] != '\0')
		len++;
	len = write(1, s, len);
	if (flag != 0)
		free(s);
	return (len);
}
