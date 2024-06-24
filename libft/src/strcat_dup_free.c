/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcat_dup_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <hakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 20:21:28 by hakoh             #+#    #+#             */
/*   Updated: 2021/07/30 16:08:06 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_new_strcat_dup_free(char *str_malloced, char *buf)
{
	int		i;
	int		j;
	char	*new_str;

	i = ft_strlen(str_malloced);
	j = ft_strlen(buf);
	new_str = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!new_str)
	{
		free(str_malloced);
		return (new_str);
	}
	ft_strcpy(new_str, str_malloced);
	j = 0;
	while (buf && buf[j])
	{
		new_str[i + j] = buf[j];
		j++;
	}
	new_str[i + j + 1] = '\0';
	free(str_malloced);
	return (new_str);
}
