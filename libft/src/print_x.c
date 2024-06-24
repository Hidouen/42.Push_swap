/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 04:16:35 by hakoh             #+#    #+#             */
/*   Updated: 2021/09/05 11:47:43 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_flagged_x(t_data *data)
{
	if (!data->flags.zero && data->flags.width > 0)
		ft_padding(data, data->flags.width, ' ');
	if (data->flags.sharp && data->arg.ulli)
		ft_putstr_to_buffer(data, "0x");
	if (data->flags.zero && data->flags.width > 0)
		ft_padding(data, data->flags.width, '0');
	if (data->flags.prec > 0)
		ft_padding(data, data->flags.prec, '0');
	ft_putuhexlow_to_buffer(data, data->arg.lli);
}

void	ft_print_x(t_data *data)
{
	if (data->flags.dot && !data->arg.ulli)
	{
		ft_xero(data);
		return ;
	}
	ft_check_hex(data);
	if (data->flags.dash && (data->flags.width > 0 || data->flags.prec > 0))
	{
		if (data->flags.sharp && data->arg.ulli)
			ft_putstr_to_buffer(data, "0x");
		if (data->flags.prec > 0)
			ft_padding(data, data->flags.prec, '0');
		ft_putuhexlow_to_buffer(data, data->arg.ulli);
		if (data->flags.width > 0)
			ft_padding(data, data->flags.width, ' ');
	}
	else if (data->flags.width > 0 || data->flags.prec > 0)
		ft_flagged_x(data);
	else
		ft_hex_print(data);
}

void	ft_flagged_upx(t_data *data)
{
	if (!data->flags.zero && data->flags.width > 0)
		ft_padding(data, data->flags.width, ' ');
	if (data->flags.sharp && data->arg.ulli)
		ft_putstr_to_buffer(data, "0X");
	if (data->flags.zero && data->flags.width > 0)
		ft_padding(data, data->flags.width, '0');
	if (data->flags.prec > 0)
		ft_padding(data, data->flags.prec, '0');
	ft_putuhexup_to_buffer(data, data->arg.ulli);
}

void	ft_xero(t_data *data)
{
	if (data->flags.dash)
	{
		if (data->flags.prec > 0)
			ft_padding(data, data->flags.prec, '0');
		if (data->flags.width)
			data->flags.width -= data->flags.prec;
		ft_padding(data, data->flags.width, ' ');
	}
	else
	{
		if (data->flags.width)
			data->flags.width -= data->flags.prec;
		ft_padding(data, data->flags.width, ' ');
		if (data->flags.prec > 0)
			ft_padding(data, data->flags.prec, '0');
	}
}

void	ft_print_upx(t_data *data)
{
	if (data->flags.dot && !data->arg.ulli)
	{
		ft_xero(data);
		return ;
	}
	ft_check_hex(data);
	if (data->flags.dash)
	{
		if (data->flags.sharp && data->arg.lli)
			ft_putstr_to_buffer(data, "0X");
		if (data->flags.prec > 0)
			ft_padding(data, data->flags.prec, '0');
		ft_putuhexup_to_buffer(data, data->arg.ulli);
		if (data->flags.width > 0)
			ft_padding(data, data->flags.width, ' ');
	}
	else if (data->flags.width > 0 || data->flags.prec > 0)
		ft_flagged_upx(data);
	else
		ft_hex_print(data);
}
