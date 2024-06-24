/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <hakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:51:08 by hakoh             #+#    #+#             */
/*   Updated: 2021/07/30 16:34:59 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	nb_words;

	i = 0;
	nb_words = 0;
	while (str[i])
	{
		while (str[i] && ft_is_in_str(str[i], charset))
			i++;
		if (str[i])
		{
			while (str[i] && !ft_is_in_str(str[i], charset))
				i++;
			nb_words++;
		}
	}
	return (nb_words);
}

char	**ft_split_all(char *str, char *charset)
{
	char	**tab;
	int		size;
	int		i;
	int		len;

	size = ft_count_words(str, charset);
	tab = (char **)malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	tab[size] = 0;
	i = 0;
	while (i < size)
	{
		len = 0;
		while (*str && ft_is_in_str(*str, charset))
			str++;
		while (str[len] && !ft_is_in_str(str[len], charset))
			len++;
		tab[i] = ft_strndup(str, len);
		if (!tab[i])
			return (NULL);
		str += len;
		i++;
	}
	return (tab);
}
