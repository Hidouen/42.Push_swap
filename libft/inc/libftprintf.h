/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 18:13:55 by hakoh             #+#    #+#             */
/*   Updated: 2021/09/07 16:13:08 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define BUFFER_SIZE 512
# define MB_SIZE 60
# define TYPES "cspdiuxX%"
# define FLAGS "-0.*# +123456789hl"
# define BASE16L "0123456789abcdef"
# define BASE16U "0123456789ABCDEF"

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef union u_types
{
	char					sc;
	unsigned char			uc;
	short int				si;
	unsigned short int		usi;
	int						i;
	unsigned int			ui;
	long int				li;
	unsigned long int		uli;
	long long int			lli;
	unsigned long long int	ulli;
	char					*scptr;
	int						*iptr;
	void					*vptr;
}	t_types;

typedef struct s_bfr
{
	char				buf[BUFFER_SIZE];
	int					i_buf;
	int					b_size;
}						t_bfr;

typedef struct s_flags
{
	int					is;
	int					dash;
	int					zero;
	int					dot;
	int					prec;
	int					width;
	int					neg;
	int					sharp;
	int					space;
	int					plus;
	int					size;
	int					h;
	int					hh;
	int					l;
	int					ll;
	int					len;
	int					minus;
	int					guest;
}	t_flags;

typedef struct s_data
{
	t_bfr				buffer;
	t_flags				flags;
	t_types				arg;
	va_list				va;
	char				*str;
	char				type;
}	t_data;

/*
** FT_PRINTF.c
*/

int						ft_printf(const char *format, ...);

/*
** GET_ARG.c
*/

void					ft_get_arg(t_data *data);
void					ft_get_sized_arg(t_data *data);
void					ft_get_sized_arg_bis(t_data *data);

/*
** PARSE.c
*/

void					ft_parse_str(t_data *data);
void					ft_parse_args(t_data *data, int *i);
int						ft_get_len(t_data *data, char c);
void					ft_else(t_data *data, int *i);

/*
** ROAD.c
*/

void					ft_compass(t_data *data, char c);
void					ft_check_flags(t_flags *flags);

/*
** FLAGS.c
*/

void					ft_parse_flags(t_data *data, int *i);
void					ft_first_flags(t_data *data, int *i);
void					ft_parse_prec(t_data *data, int *i);
int						ft_get_value(t_data *data, int *i);
void					ft_parse_size(t_data *data, int *i);

/*
** BUFFER.c
*/

void					ft_buffer_flush(t_bfr *buffer);
void					ft_putchar_to_buffer(t_data *data, char c);
void					ft_putstr_to_buffer(t_data *data, char *str);
void					ft_putnstr_to_buffer(t_data *data, char *str, int len);
void					ft_putnbr_to_buffer(t_data *data, long long n);

/*
** BUFFER_BIS.c
*/

void					ft_puthexlow_to_buffer(t_data *data, int n);
void					ft_putuhexlow_to_buffer(t_data *data,
							unsigned long long n);
void					ft_putuhexup_to_buffer(t_data *data,
							unsigned long long n);
void					ft_puthexup_to_buffer(t_data *data, int n);
void					ft_putneghexup_to_buffer(t_data *data, long long n);

/*
** UTILS.c
*/

int						ft_nb_len(int n);

/*
** UTILS_BIS.c
*/

int						ft_uns_nb_len(unsigned int n);
int						ft_uns_llnb_len(unsigned long long n);
int						ft_llnb_len(long long n);
int						ft_nb_hexlen(int n);
int						ft_llnb_len(long long n);
int						ft_uns_llnb_hexlen(unsigned long long n);

/*
** UTILS_NEXT.c
*/

int						ft_neg_nb_hexlen(long long n);
void					ft_putneghexlow_to_buffer(t_data *data, long long n);
void					ft_hex_print(t_data *data);
void					ft_putunbr_to_buffer(t_data *data,
							unsigned long long n);

/*
** PRINT_S.c
*/

void					ft_padding(t_data *data, int len, char pad_char);
void					ft_print_s(t_data *data);
void					print_s_utils(t_data *data);
void					ft_flagged_print_s(t_data *data);

/*
** PRINT_PC.c
*/

void					ft_dashed_print_p(t_data *data);
void					ft_print_p(t_data *data);
void					ft_check_p(t_data *data);
void					ft_print_c(t_data *data);

/*
** PRINT_UXDI.c
*/

void					ft_print_u(t_data *data);
void					ft_dashed_print_u(t_data *data);
void					ft_flagged_u(t_data *data);
void					ft_check_hex(t_data *data);
void					ft_check_di(t_data *data);

/*
** PRINT_X.c
*/

void					ft_print_upx(t_data *data);
void					ft_flagged_upx(t_data *data);
void					ft_print_x(t_data *data);
void					ft_flagged_x(t_data *data);
void					ft_xero(t_data *data);

/*
** PRINT_DI.c
*/

void					ft_print_di(t_data *data);
void					ft_dashed_print_di(t_data *data);
void					ft_flagged_print_di(t_data *data);
void					ft_check_neg(t_data *data);
void					ft_check_neg_next(t_data *data);

/*
** PRINT_DI_NEXT.c
*/

void					ft_zero_case(t_data *data);
void					ft_flagged_zero_di(t_data *data);
void					ft_sized(t_data *data);
void					ft_space(t_data *data);

#endif
