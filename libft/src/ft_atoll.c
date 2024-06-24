/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:59:14 by hakoh             #+#    #+#             */
/*   Updated: 2021/09/20 16:59:42 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

long long	ft_atoll(char *str)
{
	long long		sign;
	int				i;
	long long		rslt;

	i = 0;
	sign = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	rslt = 0;
	while (str[i] > 47 && str[i] < 58)
	{
		rslt *= 10;
		rslt += str[i] - 48;
		i++;
	}
	if (rslt < 0 && sign < 0)
		rslt = -1;
	else if (rslt < 0)
		rslt = 0;
	return (sign * rslt);
}
