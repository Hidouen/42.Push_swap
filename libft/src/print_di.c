/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:38:51 by hakoh             #+#    #+#             */
/*   Updated: 2021/09/05 11:40:48 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_dashed_print_di(t_data *data)
{
	if (data->flags.space || data->flags.plus || data->flags.minus)
		ft_space(data);
	if (data->flags.prec && ((data->flags.plus || data->flags.space)
			&& data->arg.lli > -1))
		data->flags.prec -= 1;
	if (data->flags.prec > 0)
	{
		data->flags.prec -= data->flags.len;
		ft_padding(data, data->flags.prec, '0');
	}
	if (data->flags.prec > 0 && data->flags.width)
		data->flags.width -= data->flags.prec;
	if (data->flags.prec && ((data->flags.plus || data->flags.space)
			&& data->arg.lli > -1))
		data->flags.width--;
	if (data->flags.size)
		ft_sized(data);
	else
		ft_putnbr_to_buffer(data, data->arg.i);
	if (data->flags.width > 0)
		ft_padding(data, data->flags.width, ' ');
}

void	ft_flagged_print_di(t_data *data)
{
	if (data->flags.prec > 0)
		data->flags.prec -= data->flags.len;
	if (data->flags.prec && ((data->flags.plus || data->flags.space)
			&& data->arg.lli > -1))
		data->flags.prec -= 1;
	if (data->flags.prec > 0 && data->flags.width)
		data->flags.width -= data->flags.prec;
	if (data->flags.dot && ((data->flags.plus || data->flags.space)
			&& data->arg.lli > -1))
		data->flags.width--;
	if (data->flags.width > 0 || data->flags.prec > 0)
	{
		if (!data->flags.zero && data->flags.width > 0)
			ft_padding(data, data->flags.width, ' ');
		if (data->flags.space || data->flags.plus || data->flags.minus)
			ft_space(data);
		if (data->flags.zero && data->flags.width > 0)
			ft_padding(data, data->flags.width, '0');
		if (data->flags.prec > 0)
			ft_padding(data, data->flags.prec, '0');
		if (data->flags.size)
			ft_sized(data);
		else
			ft_putnbr_to_buffer(data, data->arg.i);
	}
}

void	ft_print_di(t_data *data)
{
	if (data->flags.dot)
		data->flags.zero = 0;
	if ((data->arg.i == 0 && !data->flags.size) && data->flags.is
		&& data->flags.dot)
	{
		ft_zero_case(data);
		return ;
	}
	ft_check_di(data);
	if (data->flags.dash && (data->flags.width > 0 || data->flags.prec > 0))
		ft_dashed_print_di(data);
	else if (data->flags.width > 0 || (data->flags.dot
			&& data->flags.prec > -1))
		ft_flagged_print_di(data);
	else
	{
		if ((data->flags.space || data->flags.plus) || (data->flags.minus
				&& data->flags.h && data->arg.si != -32768)
			|| (data->flags.minus && !data->flags.h))
			ft_space(data);
		if (data->flags.size)
			ft_sized(data);
		else
			ft_putnbr_to_buffer(data, data->arg.i);
	}
}

void	ft_check_neg_next(t_data *data)
{
	if (data->flags.l && data->arg.li < 0)
	{
		data->arg.li *= -1;
		data->flags.minus = 1;
	}
	if (data->flags.ll && data->arg.lli < 0)
	{
		if (data->arg.lli < -9223372036854775807)
		{
			data->flags.guest = 1;
			data->arg.lli = -9223372036854775807;
		}
		data->arg.lli *= -1;
		data->flags.minus = 1;
	}
	if (data->flags.h && data->arg.si < 0)
	{
		data->arg.si *= -1;
		data->flags.minus = 1;
	}
}

void	ft_check_neg(t_data *data)
{
	if ((!data->flags.size || data->flags.hh) && data->arg.i < 0
		&& data->flags.is && (data->flags.width > 0
			|| (data->flags.dot && (data->flags.prec + 1 > data->flags.len))))
	{
		data->arg.i *= -1;
		data->flags.minus = 1;
		if (data->flags.plus || data->flags.space)
			data->flags.width++;
	}
	else
		ft_check_neg_next(data);
}
