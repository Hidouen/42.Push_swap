/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <hakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 00:12:46 by hakoh             #+#    #+#             */
/*   Updated: 2020/09/16 10:34:24 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strdup(char *str)
{
	int		len;
	char	*new;

	len = ft_strlen(str);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	new = ft_strcpy(new, str);
	return (new);
}
