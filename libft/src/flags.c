/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:27:07 by hakoh             #+#    #+#             */
/*   Updated: 2021/09/05 11:24:29 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_parse_flags(t_data *data, int *i)
{
	ft_bzero(&(data->flags), sizeof(t_flags));
	data->flags.is = 1;
	data->flags.prec = -1;
	if (data->str[*i] && ft_is_in_str(data->str[*i], FLAGS))
		ft_first_flags(data, i);
	if (data->str[*i] == '.')
		ft_parse_prec(data, i);
	if (data->str[*i] == 'l' || data->str[*i] == 'h')
	{
		data->flags.size = 1;
		ft_parse_size(data, i);
	}
}

int	ft_get_value(t_data *data, int *i)
{
	int	val;

	val = 0;
	if (data->str[*i] == '*')
	{
		val = va_arg(data->va, int);
		if (val < 0 && data->flags.dot)
			data->flags.neg = 1;
		return (val);
	}
	while (ft_isdigit((int)data->str[*i]))
	{
		val *= 10;
		val += (data->str[*i] - '0');
		(*i)++;
	}
	(*i)--;
	return (val);
}

void	ft_first_flags(t_data *data, int *i)
{
	while (data->str[*i] && ft_is_in_str(data->str[*i], FLAGS))
	{
		if (data->str[*i] == '-')
			data->flags.dash = 1;
		else if (data->str[*i] == '0')
			data->flags.zero = 1;
		else if (data->str[*i] == '#')
			data->flags.sharp = 1;
		else if (data->str[*i] == ' ')
			data->flags.space = 1;
		else if (data->str[*i] == '+')
			data->flags.plus = 1;
		else if (data->str[*i] == '*' || (ft_isdigit((int)data->str[*i])
				&& data->str[*i] != '0'))
			data->flags.width = ft_get_value(data, i);
		else if (data->str[*i] == 'l' || data->str[*i] == 'h')
			break ;
		else if (data->str[*i] == '.')
			break ;
		(*i)++;
	}
}

void	ft_parse_prec(t_data *data, int *i)
{
	(*i)++;
	data->flags.dot = 1;
	if (data->str[*i] == '-')
	{
		data->flags.neg = 1;
		(*i)++;
	}
	if (ft_isdigit((int)data->str[*i]) || data->str[*i] == '*')
	{
		data->flags.prec = ft_get_value(data, i);
		(*i)++;
	}
	else if (ft_is_in_str(data->str[*i], TYPES))
	{
		data->flags.prec = 0;
	}
}

void	ft_parse_size(t_data *data, int *i)
{
	if (data->str[*i] == 'l')
	{
		(*i)++;
		if (data->str[*i] == 'l')
		{
			data->flags.ll = 1;
			(*i)++;
		}
		else
			data->flags.l = 1;
	}
	else
	{
		(*i)++;
		if (data->str[*i] == 'h')
		{
			data->flags.hh = 1;
			(*i)++;
		}
		else
			data->flags.h = 1;
	}
}
