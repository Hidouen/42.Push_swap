/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di_next.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:41:15 by hakoh             #+#    #+#             */
/*   Updated: 2021/09/05 11:41:53 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_flagged_zero_di(t_data *data)
{
	if (data->flags.width && data->flags.zero)
		ft_padding(data, data->flags.width, '0');
	else if (data->flags.width)
		ft_padding(data, data->flags.width, ' ');
	if (data->flags.plus)
		ft_putchar_to_buffer(data, '+');
	else if (data->flags.space)
		ft_putchar_to_buffer(data, ' ');
	if (data->flags.prec > 0)
		ft_padding(data, data->flags.prec, '0');
}

void	ft_zero_case(t_data *data)
{
	if (data->flags.plus || data->flags.space)
		data->flags.width -= 1;
	if (data->flags.width && data->flags.prec > 0)
		data->flags.width -= data->flags.prec;
	if (data->flags.dash)
	{
		if (data->flags.plus)
			ft_putchar_to_buffer(data, '+');
		else if (data->flags.space)
			ft_putchar_to_buffer(data, ' ');
		if (data->flags.prec > 0)
			ft_padding(data, data->flags.prec, '0');
		if (data->flags.width)
			ft_padding(data, data->flags.width, ' ');
	}
	else
		ft_flagged_zero_di(data);
}

void	ft_space(t_data *data)
{
	if ((!data->flags.size && !data->flags.minus && (data->arg.i > -1))
		|| (data->flags.size && !data->flags.minus))
	{
		if (data->flags.space)
			ft_putchar_to_buffer(data, ' ');
		else if (data->flags.plus)
			ft_putchar_to_buffer(data, '+');
	}
	else
	{
		ft_putchar_to_buffer(data, '-');
		if (!data->flags.minus)
			data->arg.i *= -1;
	}
}

void	ft_sized(t_data *data)
{
	if (data->type == 'd' || data->type == 'i')
	{
		if (data->flags.l)
			ft_putnbr_to_buffer(data, (long long)(data->arg.li));
		else if (data->flags.ll)
		{
			ft_putnbr_to_buffer(data, (long long)(data->arg.lli));
		}
		else if (data->flags.h)
			ft_putnbr_to_buffer(data, (long long)(data->arg.si));
		else if (data->flags.hh)
			ft_putnbr_to_buffer(data, (long long)(data->arg.sc));
	}
}
