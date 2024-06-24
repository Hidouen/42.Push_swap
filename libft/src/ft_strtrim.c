/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <hakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 18:25:05 by hakoh             #+#    #+#             */
/*   Updated: 2021/07/30 16:29:35 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static void	ft_start(size_t *start, size_t *len, const char *s1,
					const char *set)
{
	*start = 0;
	*len = ft_strlen((char *)s1);
	while (ft_is_in_str(s1[*start], set))
	{
		*start += 1;
		*len -= 1;
	}
}

static void	ft_end(size_t *end, size_t *len, const char *s1, const char *set)
{
	while (ft_is_in_str(s1[*end], set))
	{
		*end -= 1;
		*len -= 1;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	len;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	if (ft_strlen((char *)s1) == 0)
		return ((char *)ft_calloc(1, sizeof(char)));
	ft_start(&start, &len, s1, set);
	end = ft_strlen((char *)s1) - 1;
	if (start > end)
		return ((char *)ft_calloc(1, sizeof(char)));
	ft_end(&end, &len, s1, set);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
		new[i++] = s1[start++];
	new[i] = '\0';
	return (new);
}
