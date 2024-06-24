/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:57:04 by hakoh             #+#    #+#             */
/*   Updated: 2020/02/14 14:53:33 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_buffer_flush(t_bfr *buffer)
{
	write(1, buffer->buf, buffer->i_buf);
	buffer->b_size += buffer->i_buf;
	buffer->i_buf = 0;
	ft_bzero(buffer->buf, BUFFER_SIZE);
}

void	ft_putchar_to_buffer(t_data *data, char c)
{
	if ((data->buffer.i_buf + 1) > BUFFER_SIZE)
		ft_buffer_flush(&(data->buffer));
	data->buffer.buf[data->buffer.i_buf++] = c;
}

void	ft_putstr_to_buffer(t_data *data, char *str)
{
	int					len;
	int					i;

	len = ft_strlen(str);
	if ((data->buffer.i_buf + len) > BUFFER_SIZE)
		ft_buffer_flush(&(data->buffer));
	i = 0;
	while (str[i])
	{
		data->buffer.buf[data->buffer.i_buf++] = str[i++];
		if (data->buffer.i_buf == BUFFER_SIZE)
			ft_buffer_flush(&(data->buffer));
	}
}

void	ft_putnstr_to_buffer(t_data *data, char *str, int size)
{
	int					i;

	if ((data->buffer.i_buf + size) > BUFFER_SIZE)
		ft_buffer_flush(&(data->buffer));
	i = 0;
	while (str[i] && size > 0)
	{
		data->buffer.buf[data->buffer.i_buf++] = str[i++];
		if (i == BUFFER_SIZE)
			ft_buffer_flush(&(data->buffer));
		size--;
	}
}

void	ft_putnbr_to_buffer(t_data *data, long long n)
{
	if ((data->buffer.i_buf + ft_llnb_len(n)) > BUFFER_SIZE)
		ft_buffer_flush(&(data->buffer));
	if (n < 0)
	{
		ft_putchar_to_buffer(data, '-');
		n *= -1;
	}
	if (n > 9)
		ft_putnbr_to_buffer(data, (n / 10));
	if (data->flags.guest && data->buffer.buf[(data->buffer.i_buf - 1)] == '0'
		&& (n % 10 == 7))
		ft_putchar_to_buffer(data, ((n % 10) + 49));
	else
		ft_putchar_to_buffer(data, ((n % 10) + 48));
}
