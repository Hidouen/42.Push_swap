/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <hakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 16:16:00 by hakoh             #+#    #+#             */
/*   Updated: 2021/07/30 15:09:29 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	tsrc;
	unsigned int	tdst;

	tsrc = ft_strlen(src);
	tdst = ft_strlen(dst);
	if (dstsize <= tdst)
		tsrc += dstsize;
	else
		tsrc += tdst;
	i = 0;
	if (dstsize > tdst)
	{
		while (src[i] && (tdst + 1) < dstsize)
		{
			dst[tdst] = src[i];
			i++;
			tdst++;
		}
		dst[tdst] = '\0';
	}
	return (tsrc);
}
