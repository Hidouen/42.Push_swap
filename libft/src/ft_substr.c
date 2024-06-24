/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <hakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:36:43 by hakoh             #+#    #+#             */
/*   Updated: 2020/09/16 10:40:58 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	size_t			i;
	unsigned int	size_str;

	if (!s)
		return (NULL);
	size_str = ft_strlen((char *)s);
	if (start > size_str)
		return ((char *)ft_calloc(1, sizeof(char)));
	if (start + len > size_str)
		len = size_str - start;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (len > 0)
	{
		new[i++] = s[start++];
		len--;
	}
	new[i] = '\0';
	return (new);
}
