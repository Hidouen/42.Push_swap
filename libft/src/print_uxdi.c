/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uxdi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:38:22 by hakoh             #+#    #+#             */
/*   Updated: 2021/09/05 11:47:07 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_check_di(t_data *data)
{
	if (data->flags.width && ((data->flags.plus || data->flags.space)
			&& data->arg.lli > -1))
		data->flags.width--;
	if (data->flags.width)
		data->flags.width -= data->flags.len;
	if (data->flags.is)
		ft_check_neg(data);
	if (data->flags.minus || (!data->flags.minus && data->arg.i < 0))
		data->flags.prec++;
	if ((data->arg.i != 0 && data->flags.width < 1) && data->flags.dot
		&& (data->flags.prec - data->flags.len) < 1)
		data->flags.dot = 0;
	if (data->flags.space || data->flags.plus)
		data->flags.prec++;
}

void	ft_dashed_print_u(t_data *data)
{
	if (data->flags.prec > 0)
	{
		if (data->arg.ulli)
			data->flags.prec -= data->flags.len;
		if (data->flags.prec > 0 && data->flags.width)
			data->flags.width -= data->flags.prec;
		ft_padding(data, data->flags.prec, '0');
	}
	if (data->arg.ulli || !data->flags.dot)
		ft_putunbr_to_buffer(data, data->arg.ulli);
	if (data->flags.width > 0)
		ft_padding(data, data->flags.width, ' ');
}

void	ft_flagged_u(t_data *data)
{
	if (data->flags.prec > 0 && data->arg.ulli)
		data->flags.prec -= data->flags.len;
	if (data->flags.prec > 0 && data->flags.width)
		data->flags.width -= data->flags.prec;
	if (data->flags.width > 0 || data->flags.prec > 0)
	{
		if (!data->flags.zero && data->flags.width > 0)
			ft_padding(data, data->flags.width, ' ');
		else if (data->flags.zero && data->flags.width > 0)
			ft_padding(data, data->flags.width, '0');
		if (data->flags.prec > 0)
			ft_padding(data, data->flags.prec, '0');
		if (!(data->arg.ulli == 0 && data->flags.dot))
			ft_putunbr_to_buffer(data, data->arg.ulli);
	}
	else if (data->arg.ulli)
		ft_putunbr_to_buffer(data, data->arg.ulli);
}

void	ft_print_u(t_data *data)
{
	if (data->flags.width && !(!data->arg.ulli && data->flags.dot))
		data->flags.width -= data->flags.len;
	if (data->flags.dot)
		data->flags.zero = 0;
	if (data->flags.dash && (data->flags.width > 0 || data->flags.prec > 0))
		ft_dashed_print_u(data);
	else if (data->flags.width > 0 || data->flags.dot)
		ft_flagged_u(data);
	else
		ft_putunbr_to_buffer(data, data->arg.ulli);
}

void	ft_check_hex(t_data *data)
{
	if (data->flags.width && data->flags.sharp)
		data->flags.width -= (data->flags.len + 2);
	else if (data->flags.width)
		data->flags.width -= data->flags.len;
	if (data->flags.dot)
		data->flags.prec -= data->flags.len;
	if (data->flags.prec > 0 && data->flags.width > 0)
		data->flags.width -= data->flags.prec;
}
