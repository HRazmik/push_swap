/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 19:14:00 by rovnania          #+#    #+#             */
/*   Updated: 2026/03/10 15:20:40 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
// # include <unistd.h>
// # include <stdlib.h>
// # include "ft_printf.h"

typedef struct s_stack_node
{
	int					value;
	int					position;
	int					stack_size;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}	t_stack_node;

typedef struct s_strat
{
	bool	simple;
	bool	medium;
	bool	complex;
	bool	adaptive;
	bool	bench;
}	t_strat;

void			ft_free(char **arr);
int				isinteger(char *nptr);
int				num_check(char *arg, int *k);
void			inicial_tflag(t_strat *yyy);
float			calculate_disorder(int arr[], int size);
int				repeating_num_check(int *arr, int j, char *str);
int				tflag_check(t_strat *yyy, int flag_count);
int				preparser_check(char **argv, int start_arg, int argc);
int				numbers_separator(char **argv, int *arr, int i, int *j);
int				*parser(char **argv, int start_arg, int argc, int arr_len);
int				comp_flag_check(int argc, char **argv, t_strat *yyy);

t_stack_node	*get_stack_a(int arr[], int len);
t_stack_node	*arguments_parsing(int argc, char **argv, t_strat *flags);
#endif