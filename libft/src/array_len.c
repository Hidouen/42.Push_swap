/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <hakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 11:05:01 by hakoh             #+#    #+#             */
/*   Updated: 2021/07/29 22:05:55 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
**  count and return how many char * there is in the array received in parameter
*/
int	array_len(char **str)
{
	int		i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}
