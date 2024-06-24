/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:18:14 by hakoh             #+#    #+#             */
/*   Updated: 2021/09/15 17:18:16 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_C
# define PUSH_SWAP_C

# include "libft.h"

# define NO_DATA 9223000000000000807
# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10
# define NB_ACTION 11

typedef struct s_stack
{
	long long		*tab;
	unsigned int	top;
}			t_stack;

typedef void (*t_action)(t_stack *,t_stack *);

typedef struct s_env
{
	long long 		*parse_tab;
	t_stack 		a;
	t_stack 		b;
	unsigned int	count;
	t_action		fun_ptr[NB_ACTION];
	unsigned int	nb_chunks;
	unsigned int	chunk_size;
	unsigned int	start;
	unsigned int	end;
}			t_env;

/*
** TO DELETE
*/
void	print_stacks(t_env *data);

/*
** Error.c
*/
void	free_before_exit(t_env *data);
void	exit_error(t_env *data, char *str);

/*
** parse.c
*/
int		only_wh(char *str);
void	check_and_count(t_env *data, char **av);
void	init_tab(long long *tab, unsigned int size);
void	init_stock(t_env *data);
int		kill_ovf(char *str);
void	stock_args(t_env *data, char **av);
int		check_dbl(long long *stack, unsigned int size);

/*
** operations1.c
*/
void	swap(t_stack *stack1, t_stack *stack2);
void	push_to(t_stack *src, t_stack *dst);
void	top_to_bottom(t_stack *stack1, t_stack *stack2);
void	bottom_to_top(t_stack *stack1, t_stack *stack2);
void	init_funptr(t_env *data);

/*
** operations2.c
*/
void	sa_action(t_stack *a, t_stack *b);
void	sb_action(t_stack *a, t_stack *b);
void	ss_action(t_stack *a, t_stack *b);
void	pa_action(t_stack *a, t_stack *b);
void	pb_action(t_stack *a, t_stack *b);

/*
** operations3.c
*/
void	ra_action(t_stack *a, t_stack *b);
void	rb_action(t_stack *a, t_stack *b);
void	rr_action(t_stack *a, t_stack *b);

/*
** operations4.c
*/
void	rra_action(t_stack *a, t_stack *b);
void	rrb_action(t_stack *a, t_stack *b);
void	rrr_action(t_stack *a, t_stack *b);

/*
** algo.c
*/
int		already_sorted(t_env *data);
void	algo_for_three(t_env *data);
unsigned int	find_smaller(t_env *data, int pos);
void	push_smaller_four(t_env *data);
void	algo_for_four(t_env *data);
// void	first_push_five(t_env *data);
// void	last_push_five(t_env *data, long long b0);
void	put_it_far(t_env *data, long long friend, unsigned int pos);
unsigned int	find_value(t_env *data, long long value);
void	algo_for_five(t_env *data);
void	few_values(t_env *data);
void	algo_handler(t_env *data);

/*
** algo2.c
*/
void	nb_chunks_def(t_env *data);
int		is_in_chunk(t_env *data, long long nb);
unsigned int
		get_cost(t_env *data, unsigned int pos);
void	main_algo(t_env *data);
void	put_it_on_top(t_env *data, long long friend, unsigned int pos);
void	sort_before_push(t_env *data);
void	apply_ope(t_env *data, unsigned int saved_pos, unsigned int cost);
void	last_step(t_env *data);

#endif