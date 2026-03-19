/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narehakobyan <narehakobyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 19:14:00 by rovnania          #+#    #+#             */
/*   Updated: 2026/03/19 17:11:51 by narehakobya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int					value;
	int					index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_count_opers
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	all_op;
}	t_count_opers;

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
int				space_skip(char *str, int *i);

void			bench(float disorder, t_count_opers op, t_strat flags);
void			del_stack(t_stack *lst);
t_stack	*lstnew_node(int number, int i, int len);
t_stack	*get_stack_a(int arr[], int len);
t_stack	*args_pars(int argc, char **argv, t_strat *flags, float *dis);
t_stack	*lstlast(t_stack *lst);

//	operations
void			sa(t_stack **a,t_count_opers *op, bool flag);
void			sb(t_stack **b,t_count_opers *op, bool flag);
void			ss(t_stack **a, t_stack **b,t_count_opers *op, bool flag);
void			ra(t_stack **a,t_count_opers *op, bool flag);
void			rb(t_stack **b,t_count_opers *op, bool flag);
void			rr(t_stack **a, t_stack **b,t_count_opers *op, bool flag);
void			rra(t_stack **a,t_count_opers *op, bool flag);
void			rrb(t_stack **b,t_count_opers *op, bool flag);
void			rrr(t_stack **a, t_stack **b, t_count_opers *op, bool flag);
void			pa(t_stack **a, t_stack **b,t_count_opers *op, bool flag);
void			pb(t_stack **a, t_stack **b,t_count_opers *op, bool flag);

//Sorting algorithms 
//void medium_sort(t_stack **a, t_stack **b);
void insertion_sort(t_stack **a, t_stack **b);
void merge_sort(t_stack **a, t_stack **b);

//esim e
int find_min(t_stack *a);
int stack_size(t_stack *a);
#endif