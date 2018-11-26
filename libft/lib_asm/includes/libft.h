/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:46:55 by bvigne            #+#    #+#             */
/*   Updated: 2018/05/25 13:41:00 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "ft_printf.h"

# define BUFF_SIZE 100

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef	struct		s_file
{
	int				fd;
	char			*buf;
	struct s_file	*next;
}					t_file;

void				ft_putchar(char c);
void				ft_putnchar(char c, int nb);
void				ft_putstr(char const *str);
void				ft_putnstr(char *str, int n);
void				ft_swap(int *a, int *b);
void				ft_putnbr(int nb);
void				ft_putunbr(long int n);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr_base(int n, int base);
void				ft_put_hex(unsigned long int nb);
void				ft_put_uhex(unsigned int nb);
void				ft_put_uhex_maj(unsigned int nb);
void				ft_memdel(void **ap);
void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
char				*ft_ctostr(char c);
char				*ft_strlowcase(char *str);
char				*ft_strupcase(char *str);
char				*ft_strcapitalize(char *str);
char				*ft_strrev(char *str);
char				*ft_strdup(const char *src);
char				*ft_strcdup(const char *src, char c);
char				*ft_strndup(const char *src, int nb);
char				*ft_strwdup(const char *src);
char				*ft_strstr(const char *to_look, const char *to_find);
char				*ft_strnstr(const char *to_look, const char *to_find,
					size_t len);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, int nb);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strccpy(char *dest, const char *src, char c);
char				*ft_strncpy(char *dest, const char *src, unsigned int n);
char				*ft_strchr(const char *s, int c);
char				*ft_strnsep(char *str, int n, char c);
char				*ft_strcend(char *s, char c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strsubdel(char *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoinfree(char *s1, char *s2);
char				*ft_charjoinfree(char *s1, char c);
char				*ft_strtrim(char const *s);
char				*ft_strnew(size_t size);
char				*ft_itoa(int n);
char				*ft_itoa_base(int n, int base);
char				**ft_split_whitespaces(char *str);
char				**ft_strsplit(char const *s, char c);
char				**ft_tabcpy(char **src);
char				**ft_tabadd(char **src, char *add);
int					*ft_nbr_split_whitespaces(char *str);
int					ft_count_white(char	*str);
int					ft_abs(int n);
int					ft_atoi(const char *str);
int					ft_atobase(char *str, char *base);
int					ft_isalpha(int i);
int					ft_str_is_alpha(char *str);
int					ft_isdigit(int i);
int					ft_isalnum(int i);
int					ft_isprint(int i);
int					ft_str_is_printable(char *str);
int					ft_isascii(int i);
int					ft_isblank(int i);
int					ft_islower(int i);
int					ft_str_is_lowercase(char *str);
int					ft_tolower(int c);
int					ft_isupper(int i);
int					ft_strnchar(char c, char *s);
int					ft_strwth(char *s, char *with);
int					ft_str_is_uppercase(char *str);
int					ft_toupper(int c);
int					ft_smallest(int n1, int n2);
int					ft_biggest(int n1, int n2);
int					ft_strend(char *str, char *end);
int					ft_nbrlen(int i);
int					ft_nbrlen_base(int n, int base);
int					ft_power(int nb, int power);
int					ft_tablen(char **tab);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, unsigned int n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					get_next_line(const int fd, char **line);
size_t				ft_strlen(const char *str);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_listlast(t_list *list);
t_list				*ft_lstaddend(t_list *begin, t_list *add);
void				ft_tabdel(char ***tab);
void				ft_lstadd(t_list **alst, t_list *add);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
int					ft_lstcount(t_list *list);

#endif
