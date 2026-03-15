/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:44:53 by rovnania          #+#    #+#             */
/*   Updated: 2026/02/28 12:46:49 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *fmt, ...);
int		ft_putstr(char *s, int flag);
int		ft_putchar(int c);
char	*ft_sitoa(int n);
char	*ft_uitoa(unsigned int n);
void	ft_print_dec(long nbr);
void	ft_print_udec(unsigned long nbr);
int		ft_print_ptr(void *ptr);
int		ft_print_hex(unsigned int num, int baza);
char	*ft_hex(unsigned long num, int len, char *base);
int		ft_print_helper(char format, va_list args);
#endif