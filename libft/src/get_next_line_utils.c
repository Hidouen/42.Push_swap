/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <hakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 06:26:41 by hakoh             #+#    #+#             */
/*   Updated: 2021/07/30 16:22:07 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

void	ft_finalfree_gnl(t_lst_gnl *ptr, t_lst_gnl **lst)
{
	t_lst_gnl	*tmp;

	tmp = *lst;
	if (*lst == ptr)
	{
		*lst = (*lst)->next;
		free(tmp);
	}
	else
	{
		while (tmp->next != ptr)
			tmp = tmp->next;
		tmp->next = ptr->next;
		free(ptr);
	}
}

void	ft_gnl_patch(char **line, t_lst_gnl **ptr, t_lst_gnl **lst)
{
	*line = (*ptr)->over;
	(*ptr)->over = NULL;
	ft_finalfree_gnl(*ptr, lst);
	if (!*line)
		*line = ft_strdup("");
}
