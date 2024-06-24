/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <hakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:41:46 by hakoh             #+#    #+#             */
/*   Updated: 2021/09/20 21:41:47 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"
# include "libftprintf.h"

/*
** conversion functions
*/
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dst, char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, char *src, size_t dstsize);
char				*ft_strnstr(char *haystack, char *needle, size_t len);
int					ft_atoi(const char *str);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(char *str);
long long			ft_atoll(char *str);

/*
** print functions
*/
void				ft_putstr_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
char				**ft_split(char const *s, char c);
char				**ft_free_split(int count, char **str);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
** t_list functions
*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
t_list				*ft_lstnew(void *content);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

/*
** other functions
*/
int					ft_is_in_str(char c, char const *str);
int					ft_long_len(long nb);
int					array_len(char **str);
void				sort_ll_tab(long long *tab, int count);

/*
** str functions
*/
int					ft_strcmp(char *s1, char *s2);
char				*ft_strndup(const char *str, size_t len);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_mystrncpy(char *dst, const char *src, size_t len);
int					c_pos_in_str(char *str, char c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcat(char *s1, const char *s2);
int					ft_strlen(char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
char				**ft_split_all(char *str, char *charset);
char				*ft_strcat_dup_free(char *over, char *buf);
int					only_signed_num(char *str);

#endif
