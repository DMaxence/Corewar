/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:43:02 by bvigne            #+#    #+#             */
/*   Updated: 2018/05/31 15:26:26 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <wchar.h>

# define CONV_LST "sSpdDioOuUxXcC"
# define ATT_LST "#0-+ "
# define MOD_LST "lhjz"
# define ALL_CHAR "#0-+ lhjz123456789.*"

# define F_HASH 	1
# define F_SPACE 	2
# define F_ZERO		4
# define F_MINUS	8
# define F_PLUS		16

# define F_L 		32
# define F_LL 		64
# define F_H		128
# define F_HH		256
# define F_J		512
# define F_Z		1024

# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"

typedef struct		s_arg
{
	int				lreg;
	char			*reg;
	int				flag;
	int				preci;
	int				larg;
	int				size;
	int				len;
	char			*arg;
	char			*buf;
}					t_arg;

typedef struct		s_conv
{
	char			conv;
	int				(*f)(t_arg*, va_list ap);
}					t_conv;

int					ft_printf(const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);
int					ft_dnprintf(int fd, int s, const char *format, ...);
int					ft_sprintf(char *str, const char *format, ...);
int					ft_snprintf(char *str, int s, const char *format, ...);

void				get_len(char *format, va_list ap, t_arg *data);
void				add_to_buf(t_arg *data);

int					parse_index(char *fmt, va_list ap, t_arg *data);
int					get_att(char *fmt, t_arg *data);
int					get_mod(char *fmt, t_arg *data);
int					get_pre(char *fmt, t_arg *data, va_list ap);
int					get_width(char *fmt, t_arg *data, va_list ap);

int					convert(char *fmt, va_list ap, t_arg *data);
void				print_rez(t_arg *data);

int					conv_none(char let, t_arg *data);
void				none_minus(t_arg *data);
void				none_space_zero(t_arg *data);

int					conv_c(t_arg *data, va_list ap);
int					conv_maj_c(t_arg *data, va_list ap);
int					conv_s(t_arg *data, va_list ap);
int					conv_maj_s(t_arg *data, va_list ap);
int					conv_i(t_arg *data, va_list ap);
int					conv_u(t_arg *data, va_list ap);
int					conv_p(t_arg *data, va_list ap);
int					conv_maj_d(t_arg *data, va_list ap);
int					conv_maj_u(t_arg *data, va_list ap);
int					conv_o(t_arg *data, va_list ap);
int					conv_maj_o(t_arg *data, va_list ap);
int					conv_x(t_arg *data, va_list ap);
int					conv_maj_x(t_arg *data, va_list ap);

int					first_uni(int c, char **uni);
int					second_uni(int c, char **uni, t_arg *data, char conv);
int					third_uni(int c, char **uni, t_arg *data, char conv);
int					fourth_uni(int c, char **uni, t_arg *data, char conv);
int					parse_exep(wchar_t c, char **res, t_arg *data);

void				pf_putchar(char c);
void				pf_putstr(const char *str);
void				pf_putnstr(char *str, int n);
void				pf_put_nb_max(intmax_t nb);
void				pf_put_u_nb_max(uintmax_t nb);

int					pf_isdigit(int i);
intmax_t			pf_abs(intmax_t n);

char				*pf_strnew(size_t size);
char				*pf_strncat(char *dest, char *src, int l_dest, int l_src);
char				*pf_strncpy(char *dest, char *src, int n);
char				*pf_strdup(char *src);
char				*pf_strndup(const char *src, int nb);

size_t				pf_strlen(const char *str);
char				*pf_strchr(const char *s, int c);
char				*pf_tolower(char *s);
void				pf_strdel(char **as);

char				*pf_strjoin(char *s1, char *s2, t_arg *data);
char				*pf_regjoin(char *s1, char *s2, t_arg *data);
char				*pf_spejoin(char *s1, char *s2, t_arg *data);
char				*pf_x_join(int n, char c, int size, t_arg *data);
char				*pf_join_x(int n, char c, int size, t_arg *data);

int					pf_atoi(const char *str);
char				*pf_itoa_base(intmax_t n, int base);
int					pf_ilen_base(intmax_t	n, int base);
char				*pf_utoa_base(uintmax_t n, int base);
int					pf_ulen_base(uintmax_t	n, int base);

#endif
