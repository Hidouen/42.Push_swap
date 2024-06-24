/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:37:59 by hakoh             #+#    #+#             */
/*   Updated: 2021/09/05 11:42:42 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_c(t_data *data)
{
	if (data->flags.width)
		data->flags.width += -1;
	if (data->flags.dash && data->flags.width)
	{
		ft_putchar_to_buffer(data, data->arg.sc);
		if (data->flags.width)
			ft_padding(data, data->flags.width, ' ');
	}
	else if (data->flags.width)
	{
		if (data->flags.width)
		{
			if (data->flags.zero)
				ft_padding(data, data->flags.width, '0');
			else
				ft_padding(data, data->flags.width, ' ');
			ft_putchar_to_buffer(data, data->arg.sc);
		}
	}
	else
		ft_putchar_to_buffer(data, data->arg.sc);
}

void	ft_check_p(t_data *data)
{
	if (data->flags.width)
		data->flags.width -= (data->flags.len + 2);
	if (data->flags.width && !data->arg.ulli && data->flags.dot
		&& !data->flags.prec)
		data->flags.width += data->flags.len;
	if (data->flags.prec > 0)
	{
		data->flags.zero = 0;
		data->flags.prec -= data->flags.len;
	}
}

void	ft_dashed_print_p(t_data *data)
{
	ft_putstr_to_buffer(data, "0x");
	if (data->flags.prec > 0)
	{
		data->flags.width -= data->flags.prec;
		ft_padding(data, data->flags.prec, '0');
	}
	ft_putuhexlow_to_buffer(data, data->arg.ulli);
	if (data->flags.width > 0)
		ft_padding(data, data->flags.width, ' ');
}

void	ft_print_p(t_data *data)
{
	ft_check_p(data);
	if (data->flags.dash && (data->flags.width > 0 || data->flags.prec > 0))
		ft_dashed_print_p(data);
	else if (data->flags.width || data->flags.dot)
	{
		if (data->flags.prec > 0 && data->flags.width)
			data->flags.width -= data->flags.prec;
		if (!data->flags.zero && data->flags.width > 0)
			ft_padding(data, data->flags.width, ' ');
		ft_putstr_to_buffer(data, "0x");
		if (data->flags.zero && data->flags.width > 0)
			ft_padding(data, data->flags.width, '0');
		if (data->flags.prec > 0)
			ft_padding(data, data->flags.prec, '0');
		ft_putuhexlow_to_buffer(data, data->arg.ulli);
	}
	else
		ft_hex_print(data);
}
