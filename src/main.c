/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <hakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:18:57 by hakoh             #+#    #+#             */
/*   Updated: 2021/09/22 20:44:00 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_env *data)
{
	unsigned int	i;

	i = data->a.top;
	ft_printf("========stackA===========\n");
	while (i + 1 > 0)
	{
		if (data->a.tab[0] == NO_DATA)
			break ;
		ft_printf("Stack A[%d] = %lld\n", i, data->a.tab[i]);
		i--;
	}
	ft_printf("=========================\n\n");
	ft_printf("========stackB===========\n");
	i = data->b.top;
	while (i + 1 > 0)
	{
		if (data->b.tab[0] == NO_DATA)
			break ;
		ft_printf("Stack B[%d] = %lld\n", i, data->b.tab[i]);
		i--;
	}
	ft_printf("=========================\n");
}

void	show_leaks(void)
{
	system("leaks push_swap");
}

int	main(int ac, char **av)
{
	t_env	data;

	ft_bzero(&data, sizeof(data));
	if (ac < 2)
		exit_error(&data, "too few arguments");
	check_and_count(&data, av);
	init_stock(&data);
	stock_args(&data, av);
	if (!check_dbl(data.parse_tab, data.count))
		exit_error(&data, "only different int values allowed");
	if (!already_sorted(&data))
		algo_handler(&data);
	free_before_exit(&data);
	return (0);
}
