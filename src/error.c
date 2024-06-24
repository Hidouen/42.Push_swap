/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:12:08 by hakoh             #+#    #+#             */
/*   Updated: 2021/09/15 19:13:42 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_before_exit(t_env *data)
{
	free(data->parse_tab);
	free(data->a.tab);
	free(data->b.tab);
}

/*
** print an error and exit the program
*/
void	exit_error(t_env *data, char *str)
{
	(void)str;
	free_before_exit(data);
	ft_printf("Error\n");
	exit(0);
}
