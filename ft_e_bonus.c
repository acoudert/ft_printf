/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_e_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 13:53:13 by acoudert          #+#    #+#             */
/*   Updated: 2020/11/27 13:53:14 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_e_n3(t_dbl *nb, double arg)
{
	nb->n3 = 0;
	while ((long long)arg > 9)
	{
		arg = arg / 10;
		nb->n3 += 1;
	}
}

void	ft_init_e_struct(t_data *data, t_dbl *nb, double arg)
{
	int		i;

	i = 0;
	nb->len2 = (data->dot != '.') ? 6 : data->prec;
	arg = ((long long)arg < 0) ? arg * (-1) : arg;
	ft_e_n3(nb, arg);
	nb->n1 = (long long)arg;
	arg = arg - (long long)arg;
	while (i++ < nb->len2)
		arg = arg * 10;
	nb->n2 = ((long long)(arg * 10) % 10 > 4) ?
		(long long)arg + 1 : (long long)arg;
	if (ft_s_nb_len(nb->n2) > data->prec)
	{
		nb->n2 = 0;
		nb->n1 += 1;
	}
	if (ft_s_nb_len(nb->n1) > 1)
	{
		nb->n1 = nb->n1 / 10;
		nb->n3 += 1;
	}
	nb->len1 = 1;
}

t_dbl	ft_e(t_data *data, double arg, int print)
{
	t_dbl	nb;
	int		sign;
	int		dot;

	ft_init_e_struct(data, &nb, arg);
	sign = ((long long)arg < 0) ? 1 : 0;
	sign = (data->indic == '+') ? 1 : sign;
	sign = (data->indic == ' ') ? 1 : sign;
	dot = (data->dot == '.' && data->prec == 0) ? 0 : 1;
	(print && data->indic != '-') ?
		ft_put_nspace(data->width - (sign + 1 + dot + nb.len2 + 4)) : 0;
	(print && (long long)arg < 0) ? ft_putchar('-') : 0;
	(print && (long long)arg > 0 && data->indic == '+') ? ft_putchar('+') : 0;
	(print && (long long)arg > 0 && data->indic == ' ') ? ft_putchar(' ') : 0;
	(print) ? ft_put_s_nb(nb.n1, 1) : 0;
	(print && dot) ? ft_putchar('.') : 0;
	(print) ? ft_put_s_nb(nb.n2, nb.len2) : 0;
	(print) ? ft_put_nstr("e+", 2) : 0;
	(print) ? ft_put_s_nb(nb.n3, 2) : 0;
	(print && data->indic == '-') ?
		ft_put_nspace(data->width - sign - 1 - dot - nb.len2 - 4) : 0;
	data->curr_len = (data->width > sign + 1 + dot + nb.len2 + 4) ?
		data->width : sign + 1 + dot + nb.len2 + 4;
	return (nb);
}
