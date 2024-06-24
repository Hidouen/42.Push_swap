/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 21:21:21 by hakoh             #+#    #+#             */
/*   Updated: 2021/09/27 21:21:25 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_action(t_stack *a, t_stack *b)
{
	bottom_to_top(a, b);
	ft_printf("rra\n");
}

void	rrb_action(t_stack *a, t_stack *b)
{
	bottom_to_top(b, a);
	ft_printf("rrb\n");
}

void	rrr_action(t_stack *a, t_stack *b)
{
	bottom_to_top(a, NULL);
	bottom_to_top(b, NULL);
	ft_printf("rrr\n");
}
