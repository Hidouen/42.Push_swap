/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:56:44 by hakoh             #+#    #+#             */
/*   Updated: 2021/09/15 19:59:09 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	only_wh(char *str)
{
	int	i;

	i = 0;
	while (str && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)
		|| str[i] == '-' || str[i] == '+'))
		i++;
	if (str && !str[i])
		return (1);
	return (0);
}

void	check_and_count(t_env *data, char **av)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 1;
	while (av[i])
	{
		if (only_wh(av[i]))
			exit_error(data, "Usage : only int values as arguments");
		tab = ft_split(av[i], ' ');
		if (!tab)
			exit_error(data, "malloc error (check_and_count() in parsing)");
		j = 0;
		k = 0;
		while (tab[k])
			k++;
		while (tab[j])
		{
			if (!only_signed_num(tab[j]))
			{
				ft_free_split(k, tab);
				exit_error(data, "Usage : only int values as arguments");
			}
			data->count++;
			j++;
		}
		ft_free_split(j, tab);
		i++;
	}
}

void	init_tab(long long *tab, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		tab[i] = NO_DATA;
		i++;
	}
}

void	init_stock(t_env *data)
{
	data->parse_tab = malloc(sizeof(long long) * data->count);
	if (!data->parse_tab)
		exit_error(data, "malloc error (init_stock() in parsing)");
	data->a.tab = malloc(sizeof(long long) * data->count);
	if (!data->a.tab)
		exit_error(data, "malloc error (init_stock() in parsing)");
	data->a.top = data->count - 1;
	data->b.tab = malloc(sizeof(long long) * data->count);
	if (!data->b.tab)
		exit_error(data, "malloc error (init_stock() in parsing)");
	data->b.top = 0;
	init_tab(data->parse_tab, data->count);
	init_tab(data->a.tab, data->count);
	init_tab(data->b.tab, data->count);
	init_funptr(data);
}

int	kill_ovf(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while ((str[i] > 8 && str[i] < 14) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	if (len - i > 12)
		return (0);
	return (1);
}

void	stock_args(t_env *data, char **av)
{
	int		i;
	int		j;
	int		k;
	char	**tab;
	int		z;

	i = 1;
	k = 0;
	while (av[i])
	{
		tab = ft_split(av[i], ' ');
		if (!tab)
			exit_error(data, "malloc error (stock_agrs() in parsing)");
		j = 0;
		z = 0;
		while (tab[z])
			z++;
		while (tab[j])
		{
			data->parse_tab[k] = ft_atoll(tab[j]);
			if (!(data->parse_tab[k] >= -2147483648 && data->parse_tab[k]
				<= 2147483647) || !kill_ovf(tab[j]))
			{
				ft_free_split(z, tab);
				exit_error(data, "Usage : only int values as arguments");
			}
			data->a.tab[data->a.top] = data->parse_tab[k++];
			data->a.top--;
			j++;
		}
		ft_free_split(j, tab);
		i++;
	}
	data->a.top = data->count - 1;
	sort_ll_tab(data->parse_tab, data->count);
}

int	check_dbl(long long *stack, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size - 1)
	{
		if (stack[i] == stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}
