/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <hakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 21:47:39 by hakoh             #+#    #+#             */
/*   Updated: 2021/10/02 19:15:52 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(t_stack *stack1, t_stack *stack2)
{
    long long    tmp;

    (void)stack2;
    tmp = stack1->tab[stack1->top];
    stack1->tab[stack1->top] = stack1->tab[stack1->top - 1];
    stack1->tab[stack1->top - 1] = tmp;
}

void    push_to(t_stack *src, t_stack *dst)
{
    long long tmp;

    tmp = src->tab[src->top];
    src->tab[src->top] = NO_DATA;
    if (src->top > 0)
        src->top--;
    if (dst->tab[dst->top] != NO_DATA)
        dst->top++;
    dst->tab[dst->top] = tmp;
}

void    top_to_bottom(t_stack *stack1, t_stack *stack2)
{
    long long        top;
    unsigned int    i;

    (void)stack2;
    i = stack1->top;
    top = stack1->tab[i];
    while (i > 0)
    {
        stack1->tab[i] = stack1->tab[i - 1];
        i--;
    }
    stack1->tab[0] = top;
}

void    bottom_to_top(t_stack *stack1, t_stack *stack2)
{
    long long        bottom;
    unsigned int    i;

    (void)stack2;
    i = 0;
    bottom = stack1->tab[i];
    while (i < stack1->top)
    {
        stack1->tab[i] = stack1->tab[i + 1];
        i++;
    }
    stack1->tab[stack1->top] = bottom;
}

void    init_funptr(t_env *data)
{
    data->fun_ptr[SA] = sa_action;
    data->fun_ptr[SB] = sb_action;
    data->fun_ptr[SS] = ss_action;
    data->fun_ptr[PA] = pa_action;
    data->fun_ptr[PB] = pb_action;
    data->fun_ptr[RA] = ra_action;
    data->fun_ptr[RB] = rb_action;
    data->fun_ptr[RR] = rr_action;
    data->fun_ptr[RRA] = rra_action;
    data->fun_ptr[RRB] = rrb_action;
    data->fun_ptr[RRR] = rrr_action;
}