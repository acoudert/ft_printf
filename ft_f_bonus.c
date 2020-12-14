/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 13:53:24 by acoudert          #+#    #+#             */
/*   Updated: 2020/11/27 13:53:25 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_f_struct(t_data *data, t_dbl *nb, double arg)
{
	int		i;

	i = 0;
	nb->len2 = (data->dot != '.') ? 6 : data->prec;
	nb->n1 = (long long)arg;
	arg = arg - (long long)arg;
	while (i < nb->len2)
	{
		arg = arg * 10;
		i++;
	}
	arg = ((long long)arg < 0) ? arg * (-1) : arg;
	nb->n2 = ((long long)(arg * 10) % 10 > 4) ?
		(long long)arg + 1 : (long long)arg;
	if (ft_s_nb_len(nb->n2) > data->prec)
	{
		nb->n2 = 0;
		nb->n1 += 1;
	}
	nb->len1 = ft_s_nb_len(nb->n1);
	nb->len1 = (nb->len1 == 0) ? nb->len1 + 1 : nb->len1;
}

t_dbl	ft_f(t_data *data, double arg, int print)
{
	t_dbl	nb;
	int		sign;
	int		dot;

	ft_init_f_struct(data, &nb, arg);
	sign = (nb.n1 < 0) ? 1 : 0;
	sign = (data->indic == '+') ? 1 : sign;
	sign = (data->indic == ' ') ? 1 : sign;
	dot = (data->dot == '.' && data->prec == 0) ? 0 : 1;
	nb.len1 = (data->indic == '0'
			&& data->width > sign + nb.len1 + dot + nb.len2) ?
				data->width - sign - dot - nb.len2 : nb.len1;
	(print && data->indic != '-') ?
		ft_put_nspace(data->width - sign - nb.len1 - dot - nb.len2) : 0;
	(print && nb.n1 < 0) ? ft_putchar('-') : 0;
	(print && nb.n1 > 0 && data->indic == '+') ? ft_putchar('+') : 0;
	(print && nb.n1 > 0 && data->indic == ' ') ? ft_putchar(' ') : 0;
	(print) ? ft_put_s_nb(nb.n1, nb.len1) : 0;
	(print && dot) ? ft_putchar('.') : 0;
	(print) ? ft_put_s_nb(nb.n2, nb.len2) : 0;
	(print && data->indic == '-') ?
		ft_put_nspace(data->width - sign - nb.len1 - dot - nb.len2) : 0;
	data->curr_len = (data->width > sign + nb.len1 + dot + nb.len2) ?
		data->width : sign + nb.len1 + dot + nb.len2;
	return (nb);
}
