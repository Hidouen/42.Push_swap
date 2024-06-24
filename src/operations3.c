/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 21:48:08 by hakoh             #+#    #+#             */
/*   Updated: 2021/09/20 21:48:10 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_action(t_stack *a, t_stack *b)
{
	top_to_bottom(a, b);
	ft_printf("ra\n");
}

void	rb_action(t_stack *a, t_stack *b)
{
	top_to_bottom(b, a);
	ft_printf("rb\n");
}

void	rr_action(t_stack *a, t_stack *b)
{
	top_to_bottom(a, NULL);
	top_to_bottom(b, NULL);
	ft_printf("rr\n");
}
