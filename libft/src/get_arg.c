/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:05:15 by hakoh             #+#    #+#             */
/*   Updated: 2021/09/05 11:29:08 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_get_arg(t_data *data)
{
	if (data->type == '%')
		data->arg.sc = '%';
	else if (data->type == 'p')
		data->arg.ulli = (unsigned long long)va_arg(data->va, void *);
	else if (data->type == 's')
	{
		data->arg.scptr = va_arg(data->va, char *);
		if (!(data->arg.scptr))
			data->arg.scptr = "(null)";
	}
	else if (data->type == 'c')
		data->arg.sc = (char)va_arg(data->va, int);
	else if (data->flags.size)
		ft_get_sized_arg(data);
	else if (data->type == 'x' || data->type == 'X' || data->type == 'u')
		data->arg.ui = va_arg(data->va, unsigned int);
	else if (data->type == 'd' || data->type == 'i')
		data->arg.i = va_arg(data->va, int);
}

void	ft_get_sized_arg(t_data *data)
{
	if (data->flags.l)
	{
		if (data->type == 'd' || data->type == 'i')
			data->arg.li = va_arg(data->va, long);
		else
			data->arg.uli = va_arg(data->va, unsigned long);
	}
	else if (data->flags.ll || data->flags.h)
		ft_get_sized_arg_bis(data);
	else
	{
		if (data->type == 'd' || data->type == 'i')
			data->arg.sc = (signed char)va_arg(data->va, int);
		else
			data->arg.uc = (unsigned char)va_arg(data->va, unsigned int);
	}
}

void	ft_get_sized_arg_bis(t_data *data)
{
	if (data->flags.ll)
	{
		if (data->type == 'd' || data->type == 'i')
			data->arg.lli = va_arg(data->va, long long);
		else
			data->arg.ulli = va_arg(data->va, unsigned long long);
	}
	else if (data->flags.h)
	{
		if (data->type == 'd' || data->type == 'i')
			data->arg.si = (short int)va_arg(data->va, int);
		else
			data->arg.usi = (unsigned short int)va_arg(data->va, unsigned int);
	}
}
