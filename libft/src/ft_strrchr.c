/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <hakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:47:09 by hakoh             #+#    #+#             */
/*   Updated: 2020/09/16 10:40:48 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strrchr(char *s, int c)
{
	int		i;
	char	*tmp;

	i = ft_strlen(s);
	if (c == 0)
		return (s + i);
	i = 0;
	tmp = NULL;
	while (s[i])
	{
		if (c == s[i])
			tmp = s + i;
		i++;
	}
	return (tmp);
}
