/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 19:14:00 by rovnania          #+#    #+#             */
/*   Updated: 2026/03/22 17:40:33 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct s_count_opers
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				all_op;
}					t_count_opers;

typedef struct s_strat
{
	bool			simple;
	bool			medium;
	bool			complex;
	bool			adaptive;
	bool			bench;
}					t_strat;

void				write_exit(void);
void				set_opers_zero(t_count_opers *op);
void				ft_free(char **arr);
int					isinteger(char *nptr);
int					num_check(char *arg, int *k);
void				inicial_tflag(t_strat *yyy);
float				calculate_disorder(int arr[], int size);
int					repeating_num_check(int *arr, int j, char *str);
int					tflag_check(t_strat *yyy, int flag_count);
int					preparser_check(char **argv, int start_arg, int argc);
int					numbers_separator(char **argv, int *arr, int i, int *j);
int					*parser(char **argv, int start_arg, int argc, int arr_len);
int					comp_flag_check(int argc, char **argv, t_strat *yyy);
int					space_skip(char *str, int *i, bool *space_flag);

void				bench(float disorder, t_count_opers op, t_strat flags);
void				del_stack(t_stack **lst);
t_stack				*lstnew_node(int number);
t_stack				*get_stack_a(int arr[], int len);
t_stack				*args_pars(int argc, char **argv, t_strat *flags,
						float *dis);
t_stack				*lstlast(t_stack *lst);

//	operations
void				sa(t_stack **a, t_count_opers *op);
void				sb(t_stack **b, t_count_opers *op);
void				ss(t_stack **a, t_stack **b, t_count_opers *op);
void				ra(t_stack **a, t_count_opers *op);
void				rb(t_stack **b, t_count_opers *op);
void				rr(t_stack **a, t_stack **b, t_count_opers *op);
void				rra(t_stack **a, t_count_opers *op);
void				rrb(t_stack **b, t_count_opers *op);
void				rrr(t_stack **a, t_stack **b, t_count_opers *op);
void				pa(t_stack **a, t_stack **b, t_count_opers *op);
void				pb(t_stack **a, t_stack **b, t_count_opers *op);

// Sorting algorithms
int					medium_sort(t_stack **a, t_stack **b, t_count_opers *op,
						int size);
int					insertion_sort(t_stack **a, t_stack **b, t_count_opers *op,
						int size);
int					radix_sort(t_stack **a, t_stack **b, t_count_opers *op,
						int size);

// esim e
t_stack				*find_min(t_stack *stack);
int					stack_size(t_stack **a);
void				assign_index(t_stack *a, int size);

#endif