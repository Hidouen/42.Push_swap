/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:54:26 by hakoh             #+#    #+#             */
/*   Updated: 2020/02/15 18:40:44 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_puthexlow_to_buffer(t_data *data, int n)
{
	char				*base;
	long				rslt;
	int					tmp[MB_SIZE];
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

void	ft_putuhexlow_to_buffer(t_data *data, unsigned long long n)
{
	char				*base;
	unsigned long long	rslt;
	int					tmp[MB_SIZE];
	int					i;

	if (!n && ((data->flags.dot && data->flags.width) || data->flags.prec != 0))
		ft_putchar_to_buffer(data, '0');
	if ((data->buffer.i_buf + ft_nb_len(n)) > BUFFER_SIZE)
		ft_buffer_flush(&(data->buffer));
	base = BASE16L;
	rslt = n;
	i = 0;
	while (rslt)
	{
		tmp[i++] = rslt % 16;
		rslt /= 16;
	}
	while (--i >= 0)
		ft_putchar_to_buffer(data, base[tmp[i]]);
}

void	ft_putuhexup_to_buffer(t_data *data, unsigned long long n)
{
	char				*base;
	unsigned long long	rslt;
	int					tmp[MB_SIZE];
	int					i;

	if (!n && data->flags.prec != 0)
		ft_putchar_to_buffer(data, '0');
	if ((data->buffer.i_buf + ft_nb_len(n)) > BUFFER_SIZE)
		ft_buffer_flush(&(data->buffer));
	base = BASE16U;
	rslt = n;
	i = 0;
	while (rslt)
	{
		tmp[i++] = rslt % 16;
		rslt /= 16;
	}
	while (--i >= 0)
		ft_putchar_to_buffer(data, base[tmp[i]]);
}

void	ft_puthexup_to_buffer(t_data *data, int n)
{
	char		*base;
	long		rslt;
	int			tmp[MB_SIZE];
	int			i;

	if (!n && data->flags.prec != 0)
		ft_putchar_to_buffer(data, '0');
	if ((data->buffer.i_buf + ft_nb_len(n)) > BUFFER_SIZE)
		ft_buffer_flush(&(data->buffer));
	base = BASE16U;
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

void	ft_putneghexup_to_buffer(t_data *data, long long n)
{
	char		*base;
	long long	rslt;
	long long	tmp[MB_SIZE];
	int			i;

	if (!n && data->flags.prec != 0)
		ft_putchar_to_buffer(data, '0');
	if ((data->buffer.i_buf + ft_nb_len(n)) > BUFFER_SIZE)
		ft_buffer_flush(&(data->buffer));
	base = BASE16U;
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
