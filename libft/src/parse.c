/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:23:36 by hakoh             #+#    #+#             */
/*   Updated: 2021/09/05 11:34:46 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_parse_str(t_data *data)
{
	int			i;

	i = 0;
	while (data->str && data->str[i])
	{
		if (data->str[i] == '%')
		{
			i++;
			ft_parse_args(data, &i);
		}
		else
		{
			ft_putchar_to_buffer(data, data->str[i]);
			i++;
		}
	}
	if (data->buffer.i_buf)
		ft_buffer_flush(&(data->buffer));
}

void	ft_parse_args(t_data *data, int *i)
{
	ft_bzero(&(data->arg), sizeof(t_types));
	ft_bzero(&(data->flags), sizeof(t_flags));
	if (!(*i < ft_strlen(data->str)))
		return ;
	if (ft_is_in_str(data->str[*i], FLAGS))
	{
		ft_parse_flags(data, i);
		ft_check_flags(&(data->flags));
	}
	if (ft_is_in_str(data->str[*i], TYPES))
	{
		if (!data->flags.dot)
			data->flags.prec = -1;
		data->type = data->str[*i];
		if (data->flags.dot && data->type != 'c' && data->type != 's'
			&& data->type != 'p' && data->type != '%')
			data->flags.zero = 0;
		ft_get_arg(data);
		data->flags.len = ft_get_len(data, data->str[*i]);
		ft_compass(data, data->str[*i]);
		(*i)++;
	}
	else
		ft_else(data, i);
}

void	ft_else(t_data *data, int *i)
{
	if (data->str[*i])
		ft_putchar_to_buffer(data, data->str[*i]);
	(*i)++;
}

int	ft_get_len(t_data *data, char c)
{
	if (c == 'c' || c == '%')
		return (1);
	else if (c == 's')
		return (ft_strlen(data->arg.scptr));
	else if (c == 'p' || c == 'x' || c == 'X')
		return (ft_uns_llnb_hexlen(data->arg.ulli));
	else if (c == 'u')
		return (ft_uns_llnb_len(data->arg.ulli));
	else if (c == 'd' || c == 'i')
		return (ft_nb_len(data->arg.lli));
	return (0);
}
