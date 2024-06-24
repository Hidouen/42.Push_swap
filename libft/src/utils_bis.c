/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:58:58 by hakoh             #+#    #+#             */
/*   Updated: 2021/09/05 11:49:20 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_uns_llnb_len(unsigned long long n)
{
	int					len;

	len = 1;
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_uns_nb_len(unsigned int n)
{
	long				res;
	int					len;

	len = 1;
	res = n;
	while (res > 9)
	{
		res /= 10;
		len++;
	}
	return (len);
}

int	ft_llnb_len(long long n)
{
	int					len;

	len = 1;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_nb_hexlen(int n)
{
	int					len;
	long				res;

	len = 1;
	res = n;
	if (n < 0)
	{
		res *= -1;
		len++;
	}
	while (res > 15)
	{
		res /= 16;
		len++;
	}
	return (len);
}

int	ft_uns_llnb_hexlen(unsigned long long n)
{
	int					len;

	len = 1;
	while (n > 15)
	{
		n /= 16;
		len++;
	}
	return (len);
}
