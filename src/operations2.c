/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 21:47:52 by hakoh             #+#    #+#             */
/*   Updated: 2021/09/20 21:47:55 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_action(t_stack *a, t_stack *b)
{
	swap(a, b);
	ft_printf("sa\n");
}

void	sb_action(t_stack *a, t_stack *b)
{
	swap(b, a);
	ft_printf("sb\n");
}

void	ss_action(t_stack *a, t_stack *b)
{
	swap(a, b);
	swap(b, a);
	ft_printf("ss\n");
}

void	pa_action(t_stack *a, t_stack *b)
{
	push_to(b, a);
	ft_printf("pa\n");
}

void	pb_action(t_stack *a, t_stack *b)
{
	push_to(a, b);
	ft_printf("pb\n");
}
