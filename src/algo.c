/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <hakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 21:52:04 by hakoh             #+#    #+#             */
/*   Updated: 2021/10/09 11:53:38 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	already_sorted(t_env *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->count - 1)
	{
		if (data->a.tab[i] < data->a.tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	algo_for_three(t_env *data)
{
	if (data->a.tab[0] > data->a.tab[1] && data->a.tab[0] > data->a.tab[2]
		&& data->a.tab[2] > data->a.tab[1])
		data->fun_ptr[SA](&data->a, NULL);
	else if (data->a.tab[0] < data->a.tab[1] && data->a.tab[0] < data->a.tab[2]
		&& data->a.tab[2] > data->a.tab[1])
	{
		data->fun_ptr[SA](&data->a, NULL);
		data->fun_ptr[RRA](&data->a, NULL);
	}
	else if (data->a.tab[0] > data->a.tab[1] && data->a.tab[0] < data->a.tab[2]
		&& data->a.tab[2] > data->a.tab[1])
		data->fun_ptr[RA](&data->a, NULL);
	else if (data->a.tab[0] > data->a.tab[2] && data->a.tab[0] < data->a.tab[1]
		&& data->a.tab[1] > data->a.tab[2])
	{
		data->fun_ptr[SA](&data->a, NULL);
		data->fun_ptr[RA](&data->a, NULL);
	}
	else if (data->a.tab[0] < data->a.tab[2] && data->a.tab[0] < data->a.tab[1]
		&& data->a.tab[1] > data->a.tab[2])
		data->fun_ptr[RRA](&data->a, NULL);
}

unsigned int	find_smaller(t_env *data, int pos)
{
	unsigned int	i;

	i = 0;
	while (i < data->count && data->a.tab[i] != data->parse_tab[pos])
		i++;
	return (i);
}

void	push_smaller_four(t_env *data)
{
	unsigned int	i;
	
	i = find_smaller(data, 0);
	if (i == 0)
		data->fun_ptr[RRA](&data->a, &data->b);
	else if (i == 1)
	{
		data->fun_ptr[RA](&data->a, &data->b);
		data->fun_ptr[RA](&data->a, &data->b);
	}
	else if (i == 2)
		data->fun_ptr[SA](&data->a, &data->b);
	data->fun_ptr[PB](&data->a, &data->b);
}

void	algo_for_four(t_env *data)
{
	push_smaller_four(data);
	algo_for_three(data);
	data->fun_ptr[PA](&data->a, &data->b);
}

void	put_it_far(t_env *data, long long friend, unsigned int pos)
{
	unsigned int	ope;
	
	if (pos > 1)
		ope = RA;
	else
		ope = RRA;
	while (data->a.tab[data->a.top] != friend)
		data->fun_ptr[ope](&data->a, &data->b);
}

unsigned int	find_value(t_env *data, long long value)
{
	unsigned int	pos;

	pos = 0;
	while (data->a.tab[pos] != value)
		pos++;
	return (pos);
}

void	algo_for_five(t_env *data)
{
	long long	small1;
	long long	small2;
	unsigned int	pos1;
	unsigned int	pos2;

	small1 = data->parse_tab[0];
	small2 = data->parse_tab[1];
	pos1 = find_value(data, small1);
	pos2 = find_value(data, small2);
	put_it_far(data, small1, pos1);
	data->fun_ptr[PB](&data->a, &data->b);
	put_it_far(data, small2, pos2);
	data->fun_ptr[PB](&data->a, &data->b);
	algo_for_three(data);
	data->fun_ptr[PA](&data->a, &data->b);
	data->fun_ptr[PA](&data->a, &data->b);
}

void	few_values(t_env *data)
{
	if (data->count == 2)
	{
		if (data->a.tab[0] < data->a.tab[1])
			data->fun_ptr[SA](&data->a, NULL);
	}
	else if (data->count == 3)
		algo_for_three(data);
	else if (data->count == 4)
		algo_for_four(data);
	else if (data->count == 5)
		algo_for_five(data);
}

void	algo_handler(t_env *data)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (data->count < 6)
		few_values(data);
	else
	{
		nb_chunks_def(data);
		data->start = 0;
		while (i < data->nb_chunks)
		{
			i++;
			data->end = data->chunk_size * i - 1;
			if (data->end >= data->count)
				data->end = data->count - 1;
			while (j <= data->end)
			{
				main_algo(data);
				j++;
			}
			if (j == data->end)
				data->start = data->end + 1;
		}
		last_step(data);
	}
}
