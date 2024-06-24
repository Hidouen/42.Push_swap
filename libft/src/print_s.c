/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:07:52 by hakoh             #+#    #+#             */
/*   Updated: 2021/09/05 11:54:18 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_padding(t_data *data, int len, char pad_char)
{
	while (len-- > 0)
		ft_putchar_to_buffer(data, pad_char);
}

void	ft_flagged_print_s(t_data *data)
{
	if (!data->flags.zero && data->flags.width > 0)
		ft_padding(data, data->flags.width, ' ');
	else if (data->flags.zero && data->flags.width > 0)
		ft_padding(data, data->flags.width, '0');
	if (data->flags.prec > 0)
		ft_putnstr_to_buffer(data, data->arg.scptr, data->flags.prec);
	else if (data->flags.width > 0 && !data->flags.dot)
		ft_putstr_to_buffer(data, data->arg.scptr);
}

void	print_s_utils(t_data *data)
{
	data->flags.dot = 0;
	data->flags.prec = -1;
}

void	ft_print_s(t_data *data)
{
	if (data->flags.dot && !(data->flags.prec < data->flags.len))
		print_s_utils(data);
	if (data->flags.dot && data->flags.width)
		data->flags.width -= data->flags.prec;
	else if (!data->flags.dot && data->flags.width)
	{
		data->flags.width -= data->flags.len;
		if (data->flags.width < 1)
			data->flags.width = 0;
	}
	if (data->flags.dash && (data->flags.width > 0 || data->flags.prec > -1))
	{
		if (data->flags.prec > -1 && data->flags.dot)
			ft_putnstr_to_buffer(data, data->arg.scptr, data->flags.prec);
		else
			ft_putstr_to_buffer(data, data->arg.scptr);
		if (data->flags.zero && data->flags.width > 0)
			ft_padding(data, data->flags.width, '0');
		else if (data->flags.width > 0)
			ft_padding(data, data->flags.width, ' ');
	}
	else if (data->flags.width > 0 || data->flags.prec > -1)
		ft_flagged_print_s(data);
	else
		ft_putstr_to_buffer(data, data->arg.scptr);
}
