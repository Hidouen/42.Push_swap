/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:09:41 by hakoh             #+#    #+#             */
/*   Updated: 2021/10/12 16:09:55 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	nb_chunks_def(t_env *data)
{
	if (data->count < 20)
		data->nb_chunks = 2;
	if (data->count < 80)
		data->nb_chunks = 4;
	else if (data->count < 200)
		data->nb_chunks = 5;
	else if (data->count < 500)
		data->nb_chunks = 10;
	else
		data->nb_chunks = 11;
	if (data->count % data->nb_chunks == 0)
		data->chunk_size = data->count / data->nb_chunks;
	else
		data->chunk_size = data->count / data->nb_chunks + 1;
}

int	is_in_chunk(t_env *data, long long nb)
{
	unsigned int	i;

	i = data->start;
	while (i <= data->end)
	{
		if (data->parse_tab[i] == nb)
			return (1);
		else
			i++;
	}
	return (0);
}

unsigned int	get_cost(t_env *data, unsigned int pos)
{
	unsigned int	rslt;

	rslt = 2147483647;
	if (pos >= (data->a.top + 1) / 2)
		rslt = data->a.top - pos;
	else
		rslt = pos + 1;
	return (rslt); 
}

void	main_algo(t_env *data)
{
	unsigned int	i;
	unsigned int	cost;
	unsigned int	saved_pos;

	i = 0;
	cost = 2147483647;
	saved_pos = 0;
	while (i <= data->a.top)
	{
		if (is_in_chunk(data, data->a.tab[i]))
		{
			if (cost > get_cost(data, i))
			{
				cost = get_cost(data, i);
				saved_pos = i;
			}
		}
		i++;
	}
	apply_ope(data, saved_pos, cost);
}

void	put_it_on_top(t_env *data, long long friend, unsigned int pos)
{
	unsigned int	ope;
	
	if (pos >= (data->b.top + 1) / 2)
		ope = RB;
	else
		ope = RRB;
	while (data->b.tab[data->b.top] != friend)
		data->fun_ptr[ope](&data->a, &data->b);
}

void	sort_before_push(t_env *data)
{
	unsigned int	friend_pos;
	unsigned int	i;
	long long		friend;

	i = 0;
	friend = -2147483649;
	friend_pos = 2147483649;
	while (i <= data->b.top)
	{
		if (data->b.tab[i] < data->a.tab[data->a.top] && data->b.tab[i] > friend)
		{
			friend = data->b.tab[i];
			friend_pos = i;
		}
		i++;
	}
	if (friend == -2147483649)
	{
		i = 0;
		while (i <= data->b.top)
		{
			if (data->b.tab[i] > friend)
			{
				friend = data->b.tab[i];
				friend_pos = i;
			}
			i++;
		}
	}
	put_it_on_top(data, friend, friend_pos);
}

void	apply_ope(t_env *data, unsigned int saved_pos, unsigned int cost)
{
	unsigned int	operation;
	unsigned int	i;
	
	i = 0;
	if (saved_pos >= (data->a.top + 1) / 2)
		operation = RA;
	else
		operation = RRA;
	while (i < cost)
	{
		data->fun_ptr[operation](&data->a, &data->b);
		i++;
	}
	if (data->b.top >= 1)
		sort_before_push(data);
	data->fun_ptr[PB](&data->a, &data->b);
}

void	last_step(t_env *data)
{
	unsigned int	friend_pos;
	unsigned int	i;
	long long		friend;

	i = 0;
	friend = -2147483649;
	friend_pos = 2147483649;
	while (i <= data->b.top)
	{
		if (data->b.tab[i] > friend)
		{
			friend = data->b.tab[i];
			friend_pos = i;
		}
		i++;
	}
	put_it_on_top(data, friend, friend_pos);
	i = data->b.top + 1;
	while (i > 0)
	{
		data->fun_ptr[PA](&data->a, &data->b);
		i--;
	}
}
