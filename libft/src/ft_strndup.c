/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <hakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:17:34 by hakoh             #+#    #+#             */
/*   Updated: 2021/07/30 15:14:15 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strndup(const char *str, size_t len)
{
	char	*new;

	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	new = ft_mystrncpy(new, (const char *)str, len);
	return (new);
}
