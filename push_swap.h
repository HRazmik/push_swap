/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 19:14:00 by rovnania          #+#    #+#             */
/*   Updated: 2026/03/07 19:10:37 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdbool.h>
// # include <unistd.h>
// # include <stdlib.h>
// # include "ft_printf.h"

typedef struct s_stack_node
{
	int					value;
	int					position;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}	t_stack_node;

typedef struct s_flag
{
	bool	simple;
	bool	medium;
	bool	complex;
	bool	adaptive;
	bool	bench;
}	t_flag;

int		comp_flag_check(int argc, char **argv, t_flag *yyy);
int		ft_parser(char **argv, int argc);
int		num_check(char *arg, int *k);
void	inicial_tflag(t_flag *yyy);
int		tflag_check(t_flag *yyy, int flag_count);
int		comp_flag_check(int argc, char **argv, t_flag *yyy);

#endif