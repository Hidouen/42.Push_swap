/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <hakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 06:47:38 by hakoh             #+#    #+#             */
/*   Updated: 2021/07/30 16:23:25 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# ifndef BUFFER_SIZE_GNL
#  define BUFFER_SIZE_GNL 32
# endif

typedef struct s_lst_gnl
{
	int					fd;
	char				*over;
	struct s_lst_gnl	*next;
}	t_lst_gnl;

int						get_next_line(int fd, char **line);
void					ft_finalfree_gnl(t_lst_gnl *ptr, t_lst_gnl **lst);
void					ft_gnl_patch(char **line, t_lst_gnl **ptr,
							t_lst_gnl **lst);

#endif
