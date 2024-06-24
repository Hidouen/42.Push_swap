/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   road.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:26:38 by hakoh             #+#    #+#             */
/*   Updated: 2021/09/05 11:48:01 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_compass(t_data *data, char c)
{
	if (c == '%' || c == 'c')
		ft_print_c(data);
	else if (c == 'u')
		ft_print_u(data);
	else if (c == 'd' || c == 'i')
		ft_print_di(data);
	else if (c == 's')
		ft_print_s(data);
	else if (c == 'x')
		ft_print_x(data);
	else if (c == 'X')
		ft_print_upx(data);
	else if (c == 'p')
		ft_print_p(data);
}

void	ft_check_flags(t_flags *flags)
{
	if (flags->width < 0)
	{
		flags->dash = 1;
		flags->width *= -1;
	}
	if (flags->neg)
	{
		flags->dot = 0;
		flags->prec = -1;
	}
	if (flags->plus)
		flags->space = 0;
	if (flags->dash)
		flags->zero = 0;
}
