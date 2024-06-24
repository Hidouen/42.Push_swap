/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:36:43 by hakoh             #+#    #+#             */
/*   Updated: 2021/09/05 11:49:40 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_neg_nb_hexlen(long long n)
{
	int					len;

	len = 1;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 15)
	{
		n /= 16;
		len++;
	}
	return (len);
}

void	ft_putneghexlow_to_buffer(t_data *data, long long n)
{
	char				*base;
	long long			rslt;
	long long			tmp[MB_SIZE];
	int					i;

	if (!n && data->flags.prec != 0)
		ft_putchar_to_buffer(data, '0');
	if ((data->buffer.i_buf + ft_nb_len(n)) > BUFFER_SIZE)
		ft_buffer_flush(&(data->buffer));
	base = BASE16L;
	rslt = n;
	if (rslt < 0)
	{
		rslt *= -1;
	}
	i = 0;
	while (rslt)
	{
		tmp[i++] = rslt % 16;
		rslt /= 16;
	}
	while (--i >= 0)
		ft_putchar_to_buffer(data, base[tmp[i]]);
}

void	ft_hex_print(t_data *data)
{
	if ((data->flags.sharp && data->arg.ulli) || data->type == 'p')
	{
		if (data->type == 'x' || data->type == 'p')
			ft_putstr_to_buffer(data, "0x");
		else if (data->type == 'X')
			ft_putstr_to_buffer(data, "0X");
	}
	if (data->type == 'x' || data->type == 'p')
		ft_putuhexlow_to_buffer(data, data->arg.ulli);
	else if (data->type == 'X')
		ft_putuhexup_to_buffer(data, data->arg.ulli);
}

void	ft_putunbr_to_buffer(t_data *data, unsigned long long n)
{
	if ((data->buffer.i_buf + ft_uns_llnb_len(n)) > BUFFER_SIZE)
		ft_buffer_flush(&(data->buffer));
	if (n > 9)
		ft_putnbr_to_buffer(data, (n / 10));
	ft_putchar_to_buffer(data, ((n % 10) + 48));
}
