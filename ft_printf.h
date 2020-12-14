/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 09:03:49 by acoudert          #+#    #+#             */
/*   Updated: 2020/11/27 13:08:39 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef FT_TAB_SIZE
#  define FT_TAB_SIZE	10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct		s_data
{
	int				count;
	int				curr_len;
	char			indic;
	int				width;
	char			dot;
	int				prec;
	char			size[2];
	char			type;
}					t_data;

typedef void		(*t_str)(t_data*, void *);

typedef struct		s_ft
{
	char			type;
	t_str			ft;
}					t_ft;

typedef struct		s_dbl
{
	long long		n1;
	long long		n2;
	int				n3;
	int				len1;
	int				len2;
}					t_dbl;

void				ft_free_struct(t_data *data);
int					ft_printf(const char *format, ...);

void				ft_init_data_struct(t_data *data);
void				ft_init_flags(t_data *data);
void				ft_init_ft_tab(t_ft *ft_tab);

int					ft_parser(t_data *data, va_list args, char *format);
int					ft_flags(t_data *data, char *format, int i, va_list args);
int					ft_args(t_data *data, va_list args);

void				ft_char(t_data *data, void *arg);
void				ft_str(t_data *data, void *arg);
void				ft_ptr(t_data *data, void *arg);
void				ft_s_nb(t_data *data, void *arg);
void				ft_u_nb(t_data *data, void *arg);
void				ft_hex(t_data *data, void *arg);
void				ft_perc(t_data *data, void *arg);
void				ft_n(t_data *data, void *arg);

void				ft_init_f_struct(t_data *data, t_dbl *nb, double arg);
t_dbl				ft_f(t_data *data, double arg, int print);

void				ft_init_e_struct(t_data *data, t_dbl *nb, double arg);
t_dbl				ft_e(t_data *data, double arg, int print);

void				ft_g(t_data *data, double arg);

void				ft_putchar(char c);
void				ft_put_nspace(int n);
void				ft_put_nstr(char *str, int len);
void				ft_put_s_nb(long long nb, int len);
void				ft_put_u_nb(unsigned long long nb, int len);
void				ft_put_hex(unsigned long long nb, int len, int type);

int					ft_strlen(char *str);
int					ft_s_nb_len(long long nb);
int					ft_u_nb_len(unsigned long long nb);
int					ft_hex_len(unsigned long long nb);

long long			ft_s_nb_cast(char *size, void *nb);
unsigned long long	ft_u_nb_cast(char *size, void *nb);

#endif
